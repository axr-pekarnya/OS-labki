#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "zmq.hpp"

int main (int argc, char const *argv[]) 
{
	void* context = zmq_ctx_new();
	void* respond = zmq_socket(context, ZMQ_REP);
	
	zmq_bind(respond, "tcp://*:4040");
	printf("Starting…\n");
	
	for(int i = 0; i < 10; ++i) 
	{
		zmq_msg_t request;
		zmq_msg_init(&request);
		zmq_msg_recv(&request, respond, 0);
		printf("Received: hello\n");
		zmq_msg_close(&request);
		zmq_msg_t reply;
		zmq_msg_init_size(&reply, strlen("world"));
		memcpy(zmq_msg_data(&reply), "world", 5);
		zmq_msg_send(&reply, respond, 0);
		zmq_msg_close(&reply);
	}
	zmq_close(respond);
	zmq_ctx_destroy(context);
	
	return 0;
}

