#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
int main(int argc , char *argv[])
{
int socket_desc;
struct sockaddr_in server;
char *message , server_reply[2000];
//Create socket
socket_desc = socket(AF_INET , SOCK_STREAM , 0);
if (socket_desc == -1)
{
printf("Could not create socket");
}
server.sin_addr.s_addr = inet_addr("127.0.0.1");
server.sin_family = AF_INET;
server.sin_port = htons( 8888 );
//Connect to remote server
if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
{
puts("connect error");
return 1;
}puts("Connected\n");
//Send
while(1)
{
	printf("Please Enter 4 num:");
	scanf("%s",message);
	if( send(socket_desc , message , strlen(message) , 0 )<0)
	{
		puts("Send failed");
		return 1;
	}
	puts("Data Send\n");
//Receive
if( recv(socket_desc, server_reply , 2000 , 0) < 0)
{
puts("recv failed");
}
puts("Reply received\n");
puts(server_reply);
if(server_reply=="Correct");
}
return 0;
}
