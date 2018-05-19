#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "hj_tcp_ip.hpp"
#include "hj_utils.hpp"

using namespace std;

int main()
{
  int size = 199692;
  int large_size = 500000;
  char memblock[size];
  memset(memblock, 0, sizeof(memblock));
  //set up a timer
  Proctimer a_timer;

  int client_socket;
  char * server_ip = (char*)"192.168.123.3";

  client_socket_create(client_socket, server_ip, 8080);
  cout << "Connected" << endl;

  int cycle = 10000;

  cout << "Start receiving " << size << " MB data for " << cycle << " times." << endl;
  a_timer.get_start_time();
  for(int i = 0; i < cycle; i++)
  {
    recv(client_socket, memblock, size, MSG_WAITALL);
  }
  a_timer.get_end_time("Totle receive");

  cout << "Received" << endl;
  //for(int i = 0; i < sizeof(memblock); i++)
  //{
  //  printf("%x", memblock[i]);
  //}
  //printf("\n");
  //ofstream o_file;
  //o_file.open("../data/dummy_received_data.bin", ios::out | ios::app | ios::binary);
  //o_file.write(memblock, size);
  //o_file.close();

  printf("Finished\n");

  return 0;
}
