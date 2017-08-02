#ifndef ODAY_LIST_H
#define ODAY_LIST_H

#include "oday_std.h"

/* ���ӷ�ʽ */
typedef enum Link_Type link_type;
enum Link_Type{
	SINGLE,									// ��������
	BOTH,									// ˫������
	SINGLE_LOOP,							// ��ѭ������
	BOTH_LOOP,								// ˫ѭ������
};

/* ������ڵ� */
typedef struct Oday_Single_List_Node oday_single_list_node;
struct Oday_Single_List_Node{
	naked_type_constraints data;			// �����ֵ
	oday_single_list_node *next;			// ������
};

/* ˫����ڵ� */
typedef struct Oday_Both_List_Node oday_both_list_node;
struct Oday_Both_List_Node{
	naked_type_constraints data;			// �����ֵ
	oday_both_list_node *prior;				// ����ǰ��
	oday_both_list_node *next;				// ������
};

/* ����ڵ� */
typedef union Oday_List_Node oday_list_node;
union Oday_List_Node{
	oday_single_list_node *single;			// ��������
	oday_both_list_node *both;				// ˫������
}; 

/* ������ */
typedef struct Oday_List_Headle* oday_list_headle;
struct Oday_List_Headle{
	data_type data_type;					// ��ϣ������
	link_type link_type;					// ���ӷ�ʽ
	unsigned int length;					// �����ܳ���
	oday_list_node head;					// ����ͷ���
	oday_list_node tail;					// ����β���
	oday_list_node nonius;					// ����ָ��
};

oday_list_headle oday_list_create(data_type data_type, link_type link_type);

/**
* ������ͷ��ѹ��һ��Ԫ��
* @param list			������
* @param value			Ԫ��ֵ
*/
void oday_list_stick(oday_list_headle list, void *value);

/**
* ������ͷ������һ��Ԫ��
* @param list			������
* @param value			����ֵ
*/
boolen oday_list_shift(oday_list_headle list, void *value);

/**
* ������β��ѹ��һ��Ԫ��
* @param list			������
* @param value			Ԫ��ֵ
*/
void oday_list_push(oday_list_headle list, void *value);

/**
* ������β������һ��Ԫ��
* @param list			������
* @param value			����ֵ
*/
boolen oday_lish_pop(oday_list_headle list, void *value);

/* ��ȡһ������ڵ����� */
void *oday_list_get(oday_list_headle list);

/* ������ָ�븴λ����λ������ͷ�� */
void oday_list_rewind(oday_list_headle list);

/* �ƶ�����ָ�� */
void *oday_list_next(oday_list_headle list);

#endif