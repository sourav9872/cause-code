#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
using namespace std;

#define IP "192.168.56.1"
int main(){
     int client,server;
    int portNum=1500;
    bool isExit=false;
    int bufsize=1024;
    char buffer[bufsize];

   // char *ip= "192.168.1.101";
     struct sockaddr_in server_addr;
     client=socket(AF_INET,SOCK_STREAM,0);
     
     if(client<0){
        cout<< "Error createing socket." <<endl;
        exit(1);
        
        }
        
         cout<< "Client Socket created." <<endl;
        server_addr.sin_family=AF_INET;
        
     server_addr.sin_addr.s_addr = inet_addr(IP);
        server_addr.sin_port=htons(portNum);
        if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        cout << "=> Connection to the server " << inet_ntoa(server_addr.sin_addr) << " with port number: " << portNum << endl; 
             recv(client,buffer,bufsize,0);
             cout<< "Connection confirmed." <<endl;
            cout<< "Enter # to end the connection." <<endl;
            
            do{
                 cout<< "Client:" << " " ;
                 do{
                     cin >> buffer;
                send(client,buffer,bufsize,0);
                 if(*buffer=='#'){
                                send(client,buffer,bufsize,0);
                                *buffer='*';
                                isExit=true;
                                }
                 }while(*buffer != 42);
                  cout<< "Server:  " << " " ;
                   do{
                                 recv(client,buffer,bufsize,0);
                                   cout<< buffer << " ";
                                    if(*buffer=='#'){
                                        *buffer='*';
                                        isExit=true; 
                                        
                                        }
                   }while(*buffer != 42);
                   cout << endl;
            }while(!isExit);
              cout<< "Connection terminated." <<endl; 
                close(client);
                return 0;
    }

