/* This is a test demonstration application that tests usage of remoteproc
and rpmsg APIs. This application is meant to run on the master CPU running Nucleus
and showcases booting of two sub-sequent remote firmware cycles using remoteproc and 
IPC with remote firmware using rpmsg; 1. It brings up a remote Nucleus based remote 
firmware which can respond to test calls, 2. It brings up a baremetal based 
remote firmware which can respond to test calls. Master app executes tests to validate
the rpmsg APIs and shutsdown the core once the test has been completed.*/

/* Including required headers */

#include  <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "open_amp.h"
#include "test_suite.h"
#include "nucleus.h"
#include "kernel/nu_kernel.h"


/* Prototypes */
static void Main_Task_Entry( UNSIGNED argc , VOID *argv );

/* Application provided callbacks */
void rpmsg_channel_created( struct rpmsg_channel *rp_chnl );
void rpmsg_channel_deleted( struct rpmsg_channel *rp_chnl );
void rpmsg_read_default_cb( struct rpmsg_channel *rp_chnl , void *data , int len , void * pric ,
                unsigned long src );
void rpmsg_read_ept1_cb( struct rpmsg_channel *rp_chnl , void *data , int len , void * pric ,
                unsigned long src );
void rpmsg_read_ept2_cb( struct rpmsg_channel *rp_chnl , void *data , int len , void * pric ,
                unsigned long src );

int test_rpmsg_send(struct rpmsg_channel *rpmsg_chnl);
int test_rpmsg_send_offchannel(struct rpmsg_channel *rpmsg_chnl, unsigned long src, unsigned long dst);

int test_rpmsg_create_ept(struct rpmsg_channel *rpmsg_chnl);

int test_remoteproc_multiple_lifecycles(char * firmware_name);

int test_rpmsg_send_offchannel_impl(struct rpmsg_channel *rpmsg_chnl, unsigned long src, unsigned long dst);

int test_rpmsg_send_impl(struct rpmsg_channel *rpmsg_chnl);

int test_rpmsg_remote_channel_deletion(struct rpmsg_channel *rpmsg_chnl, char *channel_name);

int test_execute_suite(char * firmware_name);


/* Globals */
NU_TASK Task_Control_Block;
NU_SEMAPHORE App_Sem, Remote_Del_Sem;
struct rpmsg_endpoint *rp_ept1 , *rp_ept2;
struct rpmsg_channel *app_rp_chnl;
char fw_name1[] = "firmware1";
char fw_name2[] = "firmware2";

struct _payload* p_payload = NULL;
struct _payload* r_payload = NULL;
static const char display_string[] = ".";
/***********************************************************************
 * *
 * *   FUNCTION
 * *
 * *       Application_Initialize
 * *
 * *   DESCRIPTION
 * *
 * *       Demo application entry point
 *
 * ***********************************************************************/
VOID Application_Initialize(
                NU_MEMORY_POOL* mem_pool , NU_MEMORY_POOL* uncached_mem_pool )
{
    VOID *pointer;
    STATUS status = NU_SUCCESS;

    /* Reference unused parameters to avoid toolset warnings */
    NU_UNUSED_PARAM( uncached_mem_pool );

    if ( status == NU_SUCCESS )
    {
        status = NU_Allocate_Memory(mem_pool, &pointer, STACK_SIZE, NU_NO_SUSPEND);

        /* Create the main task for matrix processing */
        if ( status == NU_SUCCESS )
        {
            status = NU_Create_Task( &Task_Control_Block , "MAIN" , Main_Task_Entry , 0 ,
                            uncached_mem_pool , pointer , STACK_SIZE , TASK_PRIORITY , TASK_SLICE ,
                            NU_PREEMPT , NU_START );
        }
        if ( status == NU_SUCCESS )
        {
            status = NU_Create_Semaphore( &App_Sem , "APP_SEM" , 0 , NU_FIFO );
        }

        if ( status == NU_SUCCESS )
        {
            status = NU_Create_Semaphore( &Remote_Del_Sem , "Del_SEM" , 0 , NU_FIFO );
        }

        NU_Allocate_Memory(uncached_mem_pool , (VOID **)&r_payload, 512 , NU_SUSPEND);
    }

    /* Check to see if previous operations were successful */
    if ( status != NU_SUCCESS )
    {
        /* Loop forever */
        while ( 1 );
    }
}

/***********************************************************************
 * *
 * *   FUNCTION
 * *
 * *       Main_Task_Entry
 * *
 * *   DESCRIPTION
 * *
 * *       Entry function for the main task. This task prints a hello world
 * *       message.
 * *
 * ***********************************************************************/
static VOID Main_Task_Entry( UNSIGNED argc , VOID *argv )
{
    printf("\n\n\r************************************");
    printf("*******************************************\r\n");
    printf("\r\n              OpenAMP Test Suite \r\n");
    printf("\r\n");
    printf("\r\nThis test suite will execute multiple test cases for rpmsg and rempteproc \r\n");
    printf("\r\nAPIs available within OpenAMP \r\n");

    printf("\r\n******************************************");
    printf("*************************************\n\r\n");

    test_execute_suite(fw_name1);

    test_execute_suite(fw_name2);


}

/* This callback gets invoked when the remote chanl is created */
void rpmsg_channel_created( struct rpmsg_channel *rp_chnl )
{
    app_rp_chnl = rp_chnl;

    rp_ept1 = rpmsg_create_ept(rp_chnl , rpmsg_read_ept1_cb , RPMSG_NULL , RPMSG_ADDR_ANY);

    NU_Release_Semaphore( &App_Sem );
}

/* This callback gets invoked when the remote channel is deleted */
void rpmsg_channel_deleted( struct rpmsg_channel *rp_chnl )
{
    rpmsg_destroy_ept( rp_ept1 );

    NU_Release_Semaphore( &Remote_Del_Sem );

}

/* This is the read callback, note we are in a task context when this callback
 is invoked, so kernel primitives can be used freely */
void rpmsg_read_default_cb( struct rpmsg_channel *rp_chnl , void *data , int len , void * priv ,
                unsigned long src )
{
    memcpy( r_payload , data , len );
    NU_Release_Semaphore( &App_Sem );
}

void rpmsg_read_ept1_cb( struct rpmsg_channel *rp_chnl , void *data , int len , void * priv ,
                unsigned long src )
{
    memcpy( r_payload , data , len );
    NU_Release_Semaphore( &App_Sem );
}

void rpmsg_read_ept2_cb( struct rpmsg_channel *rp_chnl , void *data , int len , void * priv ,
                unsigned long src )
{
    memcpy( r_payload , data , len );
    NU_Release_Semaphore( &App_Sem );
}


int test_execute_suite(char * firmware_name)
{
    struct remote_proc *proc;
    int status;
    char default_channel[] = "rpmsg-openamp-demo-channel";
    struct command* cmd;
    NU_MEMORY_POOL     *sys_pool_ptr;

    printf("\n\n\r************************************");
    printf("*******************************************\r\n");
    printf( "\r\nBoot remote context : %s \r\n" , firmware_name );
    printf("\r\n******************************************");
    printf("*************************************\n\r\n");

    status = remoteproc_init( (void *) firmware_name ,rpmsg_channel_created, rpmsg_channel_deleted, rpmsg_read_default_cb, &proc);

    if (status)
    {
        printf( "\r\n CRITICAL ERROR: remoteproc_init call for remote context %s failed \r\n", firmware_name);

        return -1;
    }

    status = remoteproc_boot( proc );

    if (status)
    {
        printf( "\r\n CRITICAL ERROR: remoteproc_boot call for remote context %s failed \r\n", firmware_name);

        return -1;
    }

    /* Wait for channel creation event */
    NU_Obtain_Semaphore( &App_Sem , NU_SUSPEND );
	
    /* Obtain remote firmware name */
    NU_System_Memory_Get(NU_NULL, &sys_pool_ptr);
    status = NU_Allocate_Memory(sys_pool_ptr , (void **)&(cmd), sizeof(struct command), NU_SUSPEND);
    cmd->comm_start=CMD_START;
    cmd->comm_code = QUERY_FW_NAME;
    status = rpmsg_send(app_rp_chnl, cmd, sizeof(struct command));
    NU_Deallocate_Memory(cmd);
	
    /* Wait to receive firmware name */
    NU_Obtain_Semaphore( &App_Sem , NU_SUSPEND );
	
    printf("\r\nREMOTE FIRMWARE NAME : %s \r\n", (char*)r_payload);

    /* Test rpmsg_send API */
    status = test_rpmsg_send(app_rp_chnl);

    if(!status)
    {
        printf( "\r\nRESULT:   PASSED \r\n" );
    }
    else
    {
        printf( "\r\nRESULT:   FAILED \r\n" );
    }

    /* Test rpmsg_send_offchannel API. */
    status = test_rpmsg_send_offchannel(app_rp_chnl, rp_ept1->addr, app_rp_chnl->dst);

    if(!status)
    {
        printf( "\r\nRESULT:   PASSED \r\n" );
    }
    else
    {
        printf( "\r\nRESULT:   FAILED \r\n" );
    }

    status = test_rpmsg_create_ept(app_rp_chnl);

    if(!status)
    {
        printf( "\r\nRESULT:   PASSED \r\n" );
    }
    else
    {
        printf( "\r\nRESULT:   FAILED \r\n" );
    }

    printf("\n\n\r************************************");
    printf("*******************************************\r\n");
    printf(" This test case will test channel deletion \r\n");
    printf("******************************************");
    printf("*************************************\r\n\n");

    status = test_rpmsg_remote_channel_deletion(app_rp_chnl, default_channel);

    if(!status)
    {
        printf( "\r\nRESULT:   PASSED \r\n" );
    }
    else
    {
        printf( "\r\nRESULT:   FAILED \r\n" );
    }

    printf("\n\n\r************************************");
    printf("*******************************************\r\n");
    printf( "\r\n\nShutdown remote context : %s \r\n" , firmware_name );
    printf("******************************************");
    printf("*************************************\r\n\n");

    status = remoteproc_shutdown(proc);
    if(!status)
    {
        status = remoteproc_deinit(proc);
    }

    if(!status)
    {
        status = test_remoteproc_multiple_lifecycles(firmware_name);
    }

    if(!status)
    {
        printf( "\r\nRESULT:   PASSED \r\n" );
    }
    else
    {
        printf( "\r\nRESULT:   FAILED \r\n" );
    }

    printf("\r\nFUNCTIONAL TEST SUITE COMPLETED EXECUTION! \r\n");

    return status;
}

int test_remoteproc_multiple_lifecycles(char * firmware_name)
{
    int i, status;
    struct remote_proc *proc;

    printf("\n\n\r************************************");
    printf("*******************************************\r\n");
    printf(" This test case will test multiple lifecycles for firmware: %s \r\n", firmware_name);
    printf("******************************************");
    printf("*************************************\r\n\n");

    for(i = 0; i < 10; i++)
    {
        status = remoteproc_init( (void *) firmware_name ,rpmsg_channel_created, rpmsg_channel_deleted, rpmsg_read_default_cb, &proc);

        if (status)
        {
            printf( "\r\n ERROR: remoteproc_init failed\r\n");

            break;
        }
		
	    printf("\n\n\r************************************");
		printf("*******************************************\r\n");
		printf( "\r\n\nBoot remote context : %s \r\n" , firmware_name );
		printf("******************************************");
		printf("*************************************\r\n\n");

        status = remoteproc_boot( proc );

        if (status)
        {
            printf( "\r\n ERROR: remoteproc_boot failed\r\n");

            break;
        }

        /* Wait for channel creation event */
        status = NU_Obtain_Semaphore( &App_Sem , NU_SUSPEND );

        if (!status)
        {
            status = test_rpmsg_send_impl(app_rp_chnl);
        }

        if(!status){
            test_rpmsg_remote_channel_deletion(app_rp_chnl , app_rp_chnl->name);
        }
		
	    printf("\n\n\r************************************");
		printf("*******************************************\r\n");
		printf( "\r\n\nShutdown remote context : %s \r\n" , firmware_name );
		printf("******************************************");
		printf("*************************************\r\n\n");

        if (!status)
        {
            status = remoteproc_shutdown(proc);
        }
        if (status)
        {
            printf( "\r\n ERROR: remoteproc_shutdown failed\r\n");

            break;
        }
        status = remoteproc_deinit(proc);

        if (status)
        {
            printf( "\r\n ERROR: remoteproc_deinit failed\r\n");

            break;
        }

        printf("%s", display_string);

    }

    return status;
}

int test_rpmsg_remote_channel_deletion(struct rpmsg_channel *rpmsg_chnl, char *channel_name)
{
    struct command *cmd;
    int status;
    NU_MEMORY_POOL     *sys_pool_ptr;
    struct chnl_cmd_data *chnl_data;

    NU_System_Memory_Get(NU_NULL, &sys_pool_ptr);

    status = NU_Allocate_Memory(sys_pool_ptr ,
                                (void **)&(cmd), sizeof(struct command)+ sizeof(struct chnl_cmd_data), NU_SUSPEND);

    cmd->comm_code = DELETE_CHNL;
    cmd->comm_start = CMD_START;

    chnl_data = (struct chnl_cmd_data *)cmd->data;

    strncpy(chnl_data->name , channel_name, sizeof(struct chnl_cmd_data));

    /* Let the other side that uninit its resources */
    status = rpmsg_send( rpmsg_chnl , cmd , sizeof(struct command) + sizeof(struct chnl_cmd_data) );
    if(status)
    {
        return status;
    }
    /* Wait for echo back */
    status = NU_Obtain_Semaphore( &App_Sem , NU_SUSPEND);
    /* Wait for channel deletion event */
    status = NU_Obtain_Semaphore( &Remote_Del_Sem , NU_SUSPEND);

    return status;
}

int test_rpmsg_create_ept(struct rpmsg_channel *rpmsg_chnl)
{
    struct command *cmd;
    int status, i;
    struct ept_cmd_data *ept_data;
    NU_MEMORY_POOL     *sys_pool_ptr;
    struct rpmsg_endpoint *test_ept[NUM_TEST_EPS];

    NU_System_Memory_Get(NU_NULL, &sys_pool_ptr);

    status = NU_Allocate_Memory(sys_pool_ptr ,
                                (void **)&(cmd), sizeof(struct command) + sizeof(struct ept_cmd_data), NU_SUSPEND);

    if(status != NU_SUCCESS)
    {
        return status;
    }
    printf("\n\n\r************************************");
    printf("*******************************************\r\n");
    printf(" This test case will test rpmsg_create_ept API \r\n");
    printf("******************************************");
    printf("*************************************\r\n\n");

    for(i = 0; i < NUM_TEST_EPS; i++)
    {
        /* Tell the remote to create a new endpoint. */
        cmd->comm_code = CREATE_EPT;
        cmd->comm_start = CMD_START;

        /* Send create endpoint command to remote */
        ept_data = (struct ept_cmd_data *)cmd->data;
        ept_data->dst= EPT_TEST_ADDR + i;
        ept_data->src= EPT_TEST_ADDR + i;

        /* Let the other side know that it needs to create endpoint with the given address */
        status = rpmsg_send(rpmsg_chnl, cmd, sizeof(struct command) + sizeof(struct ept_cmd_data));

        if(!status)
        {
            /* Wait for ack */
            status = NU_Obtain_Semaphore(&App_Sem , NU_SUSPEND);
        }

        if(!status)
        {
            printf("\r\nCreating an endpoint at address: %d \r\n", EPT_TEST_ADDR + i);

            test_ept[i] = rpmsg_create_ept(rpmsg_chnl , rpmsg_read_ept2_cb , RPMSG_NULL , EPT_TEST_ADDR + i);

            if ( !test_ept[i] )
            {
                status = -1;

                printf("\r\n ERROR: rpmsg_create_ept API failed for endpoint address: %d \r\n", EPT_TEST_ADDR + i);
            }

        }
        if(!status)
        {
            printf("\r\nTesting payloads on endpoint at address: %d \r\n", EPT_TEST_ADDR + i);

            status = test_rpmsg_send_offchannel_impl(rpmsg_chnl, test_ept[i]->addr, test_ept[i]->addr);
        }

        if(!status)
        {
            /* Tell the remote to delete the endpoint. */
            cmd->comm_code = DELETE_EPT;
            cmd->comm_start = CMD_START;
            /* Send delete endpoint command to remote */
            ept_data = (struct ept_cmd_data *)cmd->data;
            ept_data->dst= EPT_TEST_ADDR + i;
            ept_data->src= EPT_TEST_ADDR + i;

            /* Let the other side know that it needs to delete endpoint with the given address */
            status = rpmsg_send(rpmsg_chnl, cmd, sizeof(struct command) + sizeof(struct ept_cmd_data));
        }

        if(!status)
        {
            /* Wait for ack */
            status = NU_Obtain_Semaphore(&App_Sem , NU_SUSPEND);
        }

        if(!status)
        {
            rpmsg_destroy_ept(test_ept[i]);
        }
    }

    NU_Deallocate_Memory(cmd);
    if(status)
        while(1);

    return status;
}

int test_rpmsg_send_impl(struct rpmsg_channel *rpmsg_chnl)
{
    struct command cmd;
    int status;
    int i, size, idx;
    NU_MEMORY_POOL     *sys_pool_ptr;

    NU_System_Memory_Get(NU_NULL, &sys_pool_ptr);
    /* Tell the remote to be prepared for echo payloads. */
    cmd.comm_start = CMD_START;
    cmd.comm_code = START_ECHO;

    status = rpmsg_send(rpmsg_chnl, &cmd, sizeof(struct command));

    if(!status)
    {
        /* Wait for cmd ack. */
        status = NU_Obtain_Semaphore(&App_Sem , NU_SUSPEND);
        if(status)
            while(1);

        printf("\r\nTransmitting paylaods to remote \r\n");

        for(i = 0, size=PAYLOAD_MIN_SIZE; i < NUM_PAYLOADS; i++, size++)
        {
            NU_Allocate_Memory(sys_pool_ptr , (void**)&p_payload, sizeof(struct _payload) + size , NU_SUSPEND );

            p_payload->num = i;
            p_payload->size = size;

            /* Setup the buffer with a pattern*/
            memset(p_payload->data, 0xA5, size);

            /* Send data to remote side. */
            status = rpmsg_send(rpmsg_chnl, p_payload, sizeof(struct _payload) + size);

            if(status != 0)
            {
                break;
            }

            /* Wait for echo. */
            status = NU_Obtain_Semaphore(&App_Sem , NU_SUSPEND);

            /* Validate the data integrity. */
            for(idx = 0; idx < r_payload->size; idx++)
            {
                if(p_payload->data[idx] != r_payload->data[idx])
                {
                    status = -1;
                    break;
                }
            }

            if(status != 0)
            {
                break;
            }

            NU_Deallocate_Memory(p_payload);
            printf("%s", display_string);
        }
        if(status)
            while(1);
        cmd.comm_start = CMD_START;
        cmd.comm_code = STOP_ECHO;

        status = rpmsg_send(rpmsg_chnl, &cmd, sizeof(struct command));
        if(status)
            while(1);

        /* Wait for echo. */
        status = NU_Obtain_Semaphore(&App_Sem , NU_SUSPEND);
        if(status)
            while(1);
     }


    return status;
}
int test_rpmsg_send(struct rpmsg_channel *rpmsg_chnl)
{
    printf("\n\n\r************************************");
    printf("*******************************************\r\n");
    printf(" This test case will test rpmsg_send API \r\n");
    printf("******************************************");
    printf("*************************************\r\n\n");

    return test_rpmsg_send_impl(rpmsg_chnl);
}

int test_rpmsg_send_offchannel_impl(struct rpmsg_channel *rpmsg_chnl, unsigned long src, unsigned long dst)
{
    struct command cmd;
    int status;
    int i, size, idx;
    NU_MEMORY_POOL     *sys_pool_ptr;
    NU_System_Memory_Get(NU_NULL, &sys_pool_ptr);

    /* Tell the remote to be prepared for echo payloads. */
    cmd.comm_code = START_ECHO;
    cmd.comm_start = CMD_START;
    status = rpmsg_send(rpmsg_chnl, &cmd, sizeof(struct command));

    if(!status)
    {
        /* Wait for cmd ack. */
        status = NU_Obtain_Semaphore(&App_Sem , NU_SUSPEND);
        if(status)
            while(1);

        for(i = 0, size=PAYLOAD_MIN_SIZE; i < NUM_PAYLOADS; i++, size++)
        {
            NU_Allocate_Memory(sys_pool_ptr , (void**)&p_payload, sizeof(struct _payload) + size , NU_SUSPEND );
            p_payload->num = i;
            p_payload->size = size;

            /* Setup the buffer with a pattern*/
            memset(p_payload->data, 0xA5, size);

            /* Send data to remote side. */
            status = rpmsg_send_offchannel(app_rp_chnl, src, dst, p_payload ,
                                             sizeof(struct _payload) + size);

            if(status)
            {
                break;
            }

            /* Wait for echo. */
            status = NU_Obtain_Semaphore(&App_Sem , NU_SUSPEND);

            /* Validate the data integrity. */
            for(idx = 0; idx < r_payload->size; idx++)
            {
                if(p_payload->data[idx] != r_payload->data[idx])
                {
                    status = -1;
                    break;
                }
            }

            if(status)
            {
                break;
            }

            printf("%s", display_string);
            NU_Deallocate_Memory(p_payload);
        }
        cmd.comm_start = CMD_START;
        cmd.comm_code = STOP_ECHO;

        status = rpmsg_send(rpmsg_chnl, &cmd, sizeof(struct command));
        /* Wait for cmd ack. */
        status = NU_Obtain_Semaphore(&App_Sem , NU_SUSPEND);
        if(status)
            while(1);
     }

     return status;
}

int test_rpmsg_send_offchannel(struct rpmsg_channel *rpmsg_chnl, unsigned long src, unsigned long dst)
{
    printf("\n\n\r************************************");
    printf("*******************************************\r\n");
    printf(" This test case will test rpmsg_send_offchannel API \r\n");
    printf("******************************************");
    printf("*************************************\r\n\n");

    return test_rpmsg_send_offchannel_impl(rpmsg_chnl, src, dst);
}
