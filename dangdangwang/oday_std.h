#ifndef ODAY_STD_H
#define ODAY_STD_H

/* �������� */
typedef enum Data_Type data_type;
enum Data_Type{
	CHAR,			// �ַ���
	INT,			// ������
	SHORT,			// ������
	LONG,			// ������
	LONG_LONG,		// ������
	POINTER,		// ��ַ��
	STRING,			// �ַ���
};

/* �����ͳ��� */
typedef enum Boolen boolen;
enum Boolen{ TRUE = 1, FALSE = 0 };

/* ������������ */
typedef union Naked_Type_Constraints naked_type_constraints;
union Naked_Type_Constraints{
	char char_data;
	short short_data;
	int int_data;
	long long_data;
	long long long_long_data;
	void *pointer_data;
};

#endif