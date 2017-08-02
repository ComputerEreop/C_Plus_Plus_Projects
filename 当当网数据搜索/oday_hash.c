#define _CRT_SECURE_NO_WARNINGS
#include "oday_hash.h"
#include <stdlib.h>
#include <string.h>

/**
 * ����Hash��
 * @param type			������
 * @param length		����
 * @param hash_code		ɢ���㷨
 * @return �����ɹ�����Hash����
 * @return ����ʧ�ܷ���NULL 
 */
oday_hash_headle oday_hash_create(data_type type, unsigned int length, unsigned int(*hash_code)(char *str)){
	oday_hash_headle hash_table = (oday_hash_headle)malloc(sizeof(oday_hash_table));
	if (hash_table){
		hash_table->data = (oday_hash_node**)calloc(length, sizeof(oday_hash_node*));
		if (hash_table->data){
			hash_table->length = length;
			hash_table->type = type;
			hash_table->hash_code = hash_code;
			return hash_table;
		}
	}
	return NULL;
}

/* ����Hash��,�ڲ���Ҫ�˹�ϣ��ʱ���ִ�д˲��������ڴ�����ͷ�,�����������ڴ�й¶��Σ�� */
void oday_hash_destory(oday_hash_headle hash_table){
	oday_hash_node **p = hash_table->data, *temp;
	while (hash_table->length--){
		if (*p){
			temp = *p;
			*p = (*p)->next;
			free(temp);
		}
		p++;
	}
	free(hash_table->data);
	free(hash_table);
}

/**
 * ΪHash��ֵ
 * @param hash_table	��ϣ����
 * @param key			��ŵļ���
 * @param value			Ҫ�ŵļ�ֵ
 **/
void oday_hash_set(const oday_hash_headle hash_table, const char *key, const void *value){
	unsigned int offset;
	oday_hash_node *p;

	offset = hash_table->hash_code(key) % hash_table->length;
	p = *(hash_table->data + offset);

	// δ������ϣ��ײ
	if (!p){
		p = *(hash_table->data + offset) = (oday_hash_node*)malloc(sizeof(oday_hash_node));
		p->key = malloc((strlen((char*)key) + 1)*sizeof(char));
		strcpy((char*)p->key, (char*)key);
		switch (hash_table->type){
			case CHAR:
				p->data.char_data = *(char*)value;
				break;
			case SHORT:
				p->data.short_data = *(short*)value;
				break;
			case INT:
				p->data.int_data = *(int*)value;
				break;
			case LONG:
				p->data.long_data = *(long*)value;
				break;
			case LONG_LONG:
				p->data.long_long_data = *(long long*)value;
				break;
			case POINTER:
				p->data.pointer_data = value;
				break;
			case STRING:
				if (value){
					p->data.pointer_data = malloc((strlen((char*)value) + 1)*sizeof(char));
					strcpy((char*)p->data.pointer_data, (char*)value);
					break;
				}
				p->data.pointer_data = NULL;
				break;
		}
		p->next = NULL;
		return;
	}

	// ��һ����ϣ������Ǽ�ֵ
	if (!strcmp(key, p->key)){
		switch (hash_table->type){
		case CHAR:
			p->data.char_data = *(char*)value;
			return;
		case SHORT:
			p->data.short_data = *(short*)value;
			return;
		case INT:
			p->data.int_data = *(int*)value;
			return;
		case LONG:
			p->data.long_data = *(long*)value;
			return;
		case LONG_LONG:
			p->data.long_long_data = *(long long*)value;
			return;
		case POINTER:
			p->data.pointer_data = value;
			return;
		case STRING:
			if (value){
				if (p->data.pointer_data)
					p->data.pointer_data = realloc(p->data.pointer_data, (strlen((char*)value) + 1)*sizeof(char));
				else
					p->data.pointer_data = malloc((strlen((char*)value) + 1)*sizeof(char));
				strcpy((char*)p->data.pointer_data, (char*)value);
				return;
			}
			if (p->data.pointer_data){
				free(p->data.pointer_data);
				p->data.pointer_data = NULL;
			}
			return;
		}
		return;
	}

	// �ǵ�һ����ײ�ڵ�
	while (p->next){
		p = p->next;
		if (!strcmp(key, p->key)){
			switch (hash_table->type){
			case CHAR:
				p->data.char_data = *(char*)value;
				return;
			case SHORT:
				p->data.short_data = *(short*)value;
				return;
			case INT:
				p->data.int_data = *(int*)value;
				return;
			case LONG:
				p->data.long_data = *(long*)value;
				return;
			case LONG_LONG:
				p->data.long_long_data = *(long long*)value;
				return;
			case POINTER:
				p->data.pointer_data = value;
				return;
			case STRING:
				if (value){
					if (p->data.pointer_data)
						p->data.pointer_data = realloc(p->data.pointer_data, (strlen((char*)value) + 1)*sizeof(char));
					else
						p->data.pointer_data = malloc((strlen((char*)value) + 1)*sizeof(char));
					strcpy((char*)p->data.pointer_data, (char*)value);
					return;
				}
				if (p->data.pointer_data){
					free(p->data.pointer_data);
					p->data.pointer_data = NULL;
				}
				return;
			}
			return;
		}
	}

	p->next = (oday_hash_node*)malloc(sizeof(oday_hash_node));
	if (!p->next){
		printf("�ڴ����ʧ�ܣ�\n");
		return;
	}
	p = p->next;
	p->key = malloc((strlen((char*)key) + 1)*sizeof(char));
	if (!p->key){
		printf("�ڴ����ʧ�ܣ�\n");
		return;
	}
	strcpy((char*)p->key, (char*)key);
	switch (hash_table->type){
	case CHAR:
		p->data.char_data = *(char*)value;
		break;
	case SHORT:
		p->data.short_data = *(short*)value;
		break;
	case INT:
		p->data.int_data = *(int*)value;
		break;
	case LONG:
		p->data.long_data = *(long*)value;
		break;
	case LONG_LONG:
		p->data.long_long_data = *(long long*)value;
		break;
	case POINTER:
		p->data.pointer_data = value;
		break;
	case STRING:
		if (value){
			p->data.pointer_data = malloc((strlen((char*)value) + 1)*sizeof(char));
			strcpy((char*)p->data.pointer_data, (char*)value);
			break;
		}
		p->data.pointer_data = NULL;
		break;
	}
	p->next = NULL;
}

/**
 * �鿴һ��Hash���е�ֵ
 * @param hash_table	��ϣ����
 * @param key			��ŵļ���
 * @return ���ݴ�ŵĵ�ַ,Ϊ�ձ�ʾ�ڵ㲻����
 **/
void *oday_hash_get(const oday_hash_headle hash_table, const char *key){
	unsigned int offset;
	oday_hash_node *p;

	offset = hash_table->hash_code(key) % hash_table->length;
	p = *(hash_table->data + offset);

	while (p){
		if (!strcmp(key, p->key)){
			switch (hash_table->type){
			case CHAR:
				return (void*)&p->data.char_data;
			case SHORT:
				return (void*)&p->data.short_data;
			case INT:
				return (void*)&p->data.int_data;
			case LONG:
				return (void*)&p->data.long_data;
			case LONG_LONG:
				return (void*)&p->data.long_long_data;
			case POINTER:
				return p->data.pointer_data;
			case STRING:
				return p->data.pointer_data;
			}
			return NULL;
		}
		p = p->next;
	}
	return NULL;
}

/**
 * ����һ��Hash��
 * @param hash_table	��ϣ����
 * @param key			��ŵļ���
 * @param result		��Ž��
 **/
void oday_hash_pop(const oday_hash_headle hash_table, const char *key, void *result){
	unsigned int offset;
	oday_hash_node *p,*temp;

	offset = hash_table->hash_code(key) % hash_table->length;
	p = *(hash_table->data + offset);

	if (!p){
		result = NULL;
		return NULL;
	}

	// ��һ����ϣ������Ǽ�ֵ
	if (!strcmp(key, p->key)){
		switch (hash_table->type){
		case CHAR:
			*(char*)result = p->data.char_data;
			break;
		case SHORT:
			*(short*)result = p->data.short_data;
			break;
		case INT:
			*(int*)result = p->data.int_data;
			break;
		case LONG:
			*(long*)result = p->data.long_data;
			break;
		case LONG_LONG:
			*(long long*)result = p->data.long_long_data;
			break;
		case POINTER:
			result = p->data.pointer_data;
			break;
		case STRING:
			result = p->data.pointer_data;
			break;
		}
		free(p);
		return NULL;
	}

	// �ǵ�һ����ײ�ڵ�
	while (p->next){
		if (!strcmp(key, p->next->key)){
			temp = p->next;
			p->next = temp->next;
			switch (hash_table->type){
			case CHAR:
				*(char*)result = temp->data.char_data;
				break;
			case SHORT:
				*(short*)result = temp->data.short_data;
				break;
			case INT:
				*(int*)result = temp->data.int_data;
				break;
			case LONG:
				*(long*)result = temp->data.long_data;
				break;
			case LONG_LONG:
				*(long long*)result = temp->data.long_long_data;
				break;
			case POINTER:
				result = temp->data.pointer_data;
				break;
			case STRING:
				result = temp->data.pointer_data;
				break;
			}
			free(temp);
			return;
		}
		p = p->next;
	}
	result = NULL;
	return NULL;
}

/**
* ��ʼ��Hash�������
* @param hash_table		��ϣ����
* @param iterator		��ϣ������
*/
void oday_hash_iterator_init(oday_hash_headle hash_table, oday_hash_iterator *iterator){
	unsigned int length = hash_table->length;
	iterator->table = hash_table;
	iterator->code = hash_table->data;
	iterator->node = NULL;
	while (length){
		if (*iterator->code){
			iterator->node = *iterator->code;
			return;
		}
		iterator->node++;
		length--;
	}
}

/* SDBM Hash �㷨 */
unsigned int oday_SDBMHash(char *str){
	unsigned int hash = 0;
	while (*str)
		hash = (*str++) + (hash << 6) + (hash << 16) - hash;
	return (hash & 0x7FFFFFFF);
}

/* RS Hash �㷨 */
unsigned int oday_RSHash(char *str){
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;
	while (*str){
		hash = hash * a + (*str++);
		a *= b;
	}
	return (hash & 0x7FFFFFFF);
}

/* JS Hash �㷨 */
unsigned int oday_JSHash(char *str){
	unsigned int hash = 1315423911;
	while (*str)
		hash ^= (hash << 5) + (*str++) + (hash >> 2);
	return (hash & 0x7FFFFFFF);
}

/* P.J.Weinberger Hash �㷨 */
unsigned int oday_PJWHash(char *str){
	unsigned int BitsInUnignedInt = (unsigned int)(sizeof(unsigned int)* 8);
	unsigned int ThreeQuarters = (unsigned int)((BitsInUnignedInt * 3) / 4);
	unsigned int OneEnglish = (unsigned int)(BitsInUnignedInt / 8);
	unsigned int HighBits = (unsigned int)(0xFFFFFFFF) << (BitsInUnignedInt - OneEnglish);
	unsigned int hash = 0;
	unsigned int test = 0;
	while (*str){
		hash = (hash << OneEnglish) + (*str++);
		if ((test = hash & HighBits) != 0)
			hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
	}
	return (hash & 0x7FFFFFFF);
}

/* ELF Hash �㷨 */
unsigned int oday_ELFHash(char *str){
	unsigned int hash = 0;
	unsigned int x = 0;
	while (*str){
		hash = (hash << 4) + (*str++);
		if ((x = hash & 0xF000000L) != 0){
			hash ^= (x >> 24);
			hash &= ~x;
		}
	}
	return (hash & 0x7FFFFFFF);
}

/* BKDR Hash �㷨 */
unsigned int oday_BKDRHash(char *str){
	// 31 131 1313 13131 131313 etc
	unsigned int seed = 131;
	unsigned int hash = 0;
	while (*str)
		hash = hash * seed + (*str++);
	return (hash & 0x7FFFFFFF);
}

/* DJB Hash �㷨 */
unsigned int oday_DJBHash(char *str){
	unsigned int hash = 5381;
	while (*str)
		hash += (hash << 5) + (*str++);
	return (hash & 0x7FFFFFFF);
}

/* AP Hash �㷨 */
unsigned int oday_APhash(char *str){
	unsigned int hash = 0;
	int i;
	for (i = 0; *str; i++){
		if ((i & 1) == 0)
			hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
		else
			hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));
	}
	return (hash & 0x7FFFFFFF);
}