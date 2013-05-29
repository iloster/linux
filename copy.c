/*
 *
 *  Created on: May 14, 2012
 *      Author: dell
 *  copy data from S to T
 */
#include "signalmove.h"

void copy() {
	while (1) {
		sem_wait(&copy_sem);
		pthread_mutex_lock(&read_mutex);
		pthread_mutex_lock(&write_mutex);
		printf("copy..........\n");
		strcpy(data_t,data_s);
		int i=0;
		for(;i<len;i++){
			data_s[i]=' ';
		}
		printf("copy..........complete\n");
		pthread_mutex_unlock(&write_mutex);
		pthread_mutex_unlock(&read_mutex);
		sem_post(&write_sem);
		sem_post(&read_sem);
		if (result == 0) {
			result_copy = 1;
			break;
		}
	}
}
