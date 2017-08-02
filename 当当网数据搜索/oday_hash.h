#ifndef ODAY_HASH_H
#define ODAY_HASH_H

// ����oday���׼ͷ
#include <stdio.h>
#include "oday_std.h"

/* Hash�ڵ�ṹ�� */
typedef struct Oday_Hash_Node oday_hash_node;
struct Oday_Hash_Node{
	char *key;								// ��ϣ����
	naked_type_constraints data;			// ��ϣ��ֵ
	oday_hash_node *next;					// ��һ�ڵ�
};

/* Hash��ṹ�� */
typedef struct Oday_Hash_Table* oday_hash_headle;
typedef struct Oday_Hash_Table oday_hash_table;
typedef struct Oday_Hash_Table{
	unsigned int length;					// ��ϣ����
	data_type type;							// ��ϣ������
	oday_hash_node **data;					// ��ϣ��ڵ�
	unsigned int(*hash_code)(char *str);	// ��ϣcode
};

/* Hash������� */
typedef struct Oday_Hash_Iterator oday_hash_iterator;
struct Oday_Hash_Iterator{
	oday_hash_headle table;					// ��ϣ����
	oday_hash_node **code;					// ��ϣ��ڵ�
	oday_hash_node *node;					// ��ϣ����Ŀ
};

/**
* ����Hash��
* @param type			������
* @param length			����
* @param hash_code		ɢ���㷨
* @return �����ɹ�����Hash����
* @return ����ʧ�ܷ���NULL
*/
oday_hash_headle oday_hash_create(data_type type, unsigned int length, unsigned int(*hash_code)(char *str));

/**
* ����Hash��
*/
void oday_hash_destory(oday_hash_headle hash_table);

/**
* ΪHash��ֵ
* @param hash_table		��ϣ����
* @param key			��ŵļ���
* @param value			Ҫ�ŵļ�ֵ
**/
void oday_hash_set(const oday_hash_headle hash_table, const char *key, const void *value);

/**
* �鿴һ��Hash���е�ֵ
* @param hash_table		��ϣ����
* @param key			��ŵļ���
* @return ���ݴ�ŵĵ�ַ,Ϊ�ձ�ʾ�ڵ㲻����
**/
void *oday_hash_get(const oday_hash_headle hash_table, const char *key);

/**
* ����һ��Hash��
* @param hash_table		��ϣ����
* @param key			��ŵļ���
* @param result			��Ž��
**/
void oday_hash_pop(const oday_hash_headle hash_table, const char *key, void *result);

/**
 * ��ʼ��Hash�������
 * @param hash_table	��ϣ����
 * @param iterator		��ϣ������
 */
void oday_hash_iterator_init(oday_hash_headle hash_table, oday_hash_iterator *iterator);

/* SDBM Hash �㷨 */
unsigned int oday_SDBMHash(char *str);

/* RS Hash �㷨 */
unsigned int oday_RSHash(char *str);

/* JS Hash �㷨 */
unsigned int oday_JSHash(char *str);

/* P.J.Weinberger Hash �㷨 */
unsigned int oday_PJWHash(char *str);

/* ELF Hash �㷨 */
unsigned int oday_ELFHash(char *str);

/* BKDR Hash �㷨 */
unsigned int oday_BKDRHash(char *str);

/* DJB Hash �㷨 */
unsigned int oday_DJBHash(char *str);

/* AP Hash �㷨 */
unsigned int oday_APhash(char *str);

#endif