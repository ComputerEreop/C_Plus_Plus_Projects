#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "oday_hash.h"
#include "oday_list.h"
#include <sys/timeb.h>

long long getTime();
unsigned long long load_file(char filename[], char **buffer);
void read_key(char *key, char *source);

int main(){
	oday_hash_headle dangdang_table;
	oday_list_headle list;
	char *buffer = NULL, key[100], *str, input[100] ,*result, temp[1000];
	unsigned long long i = 0, size, start;

	printf("���������ļ�...");

	// ��ʱ��ʼ
	start = getTime();

	if (size = load_file("dangdangwang.txt", &buffer)){
		printf("...�������,�ļ���С��%d,��ʱ��%udms\n", size, getTime() - start);
	}
	else{
		printf("...����ʧ��,�������\n");
		system("pause");
		return 0;
	}

	dangdang_table = oday_hash_create(POINTER, 100000, oday_BKDRHash);
	list = oday_list_create(POINTER, SINGLE);

	printf("��ʼ�����ļ�...\n");

	// ��ʱ��ʼ
	start = getTime();

	str = strtok(buffer, "\n");
	read_key(key, strchr(str, ',') + 1);
	oday_hash_set(dangdang_table, key, str);
	while (str = strtok(NULL, "\n")){
		read_key(key, strchr(str, ',') + 1);
		list = (oday_list_headle)oday_hash_get(dangdang_table, key);
		if (list){
			oday_list_stick(list, str);
		}
		else{
			list = oday_list_create(POINTER, SINGLE);
			oday_list_stick(list, str);
			oday_hash_set(dangdang_table, key, list);
		}
		if (i++ > 500000){
			i = 0;
			printf("���%.2f%%\n", 100.0*(double)(str - buffer) / (double)size);
		}
	}
	printf("���100.00%%,��ʱ��%udms\n", 100.0*(double)(str - buffer) / (double)size, getTime() - start);

	printf("��������Ҫ��ѯ��������");
	while (scanf("%s", input)){

		// ��ʱ��ʼ
		start = getTime();

		if (strcmp(input, "ext") == 0)
			return 0;
		list = (oday_list_headle)oday_hash_get(dangdang_table, input);
		if (list){
			oday_list_rewind(list);
			while (result = (char*)oday_list_next(list)){
			//	printf("��ʱ��%dms\n%s\n", getTime() - start, result);
				printf("��ʱ��%dms\n", getTime() - start);
				printf("%s\n", result);
			}
		}
		else
			printf("���ҵ����ݲ�����,��ʱ��%udms!\n",getTime() - start);
		printf("������Ҫ��ѯ��������");
	}
	oday_hash_destory(dangdang_table);
	system("pause");
}

/* ���ļ������ڴ� */
unsigned long long load_file(char filename[], char **buffer){
	FILE *dist;						// �ʿ��ļ����
	unsigned long long size;		// �ļ���С

	// ��Ŀ���ļ�
	dist = fopen(filename, "r");
	if (!dist)
		return 0;

	// ��ȡ�ļ���С
	fseek(dist, 0, SEEK_END);
	size = (unsigned)ftell(dist);
	rewind(dist);

	// ���ļ����뻺����
	*buffer = (char*)malloc(sizeof(char)*(size+1));
	fread(*buffer, 1, size, dist);
	return size;
}

void read_key(char *key, char *source){
	while (*source!=',')
		*key++ = *source++;
	*key = 0;
}

long long getTime() {
	struct timeb t;
	ftime(&t);
	return 1000 * t.time + t.millitm;
}