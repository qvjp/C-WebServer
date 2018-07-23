#include <stdio.h>
#include "/usr/local/mysql/include/mysql.h"
#include <string.h>
void printResult(MYSQL *mysql, char buf[]);
int findTeacherById(int id, char buf[]);

void updateStudentById(int id, char password[]);
void updateTeacherById(int id, char password[]);
int query(char buf[], int num, int type)
{
    MYSQL mysql;
    MYSQL_RES * result;
    mysql_init(&mysql);
    mysql_real_connect(&mysql, "localhost", "root", "qjp123MS..", NULL, 3306, NULL, 0); 
    mysql_query(&mysql, "set names 'utf8'");
    // mysql_query(&mysql, "drop database if exists tmpdb");
    // mysql_query(&mysql, "create database tmpdb");
    mysql_query(&mysql, "use exam");
    // mysql_query(&mysql, "create table tmptab(c1 int, c2 varchar(20), c3 varchar(20))");
    // mysql_query(&mysql, "insert into tmptab values(101, '姓名1', 'address1'), (102, '姓名2', 'address2'), (103, '姓名3', 'address3')");
    // mysql_query(&mysql, "select * from tmptab");
    // printf("--增加数据测试--\n");
    // printResult(&mysql);
    // mysql_query(&mysql, "delete from tmptab where c1 = 101");
    // mysql_query(&mysql, "select * from tmptab");
    // printf("--删除数据测试--\n");
    // printResult(&mysql);
    // mysql_query(&mysql, "update tmptab set c3 = 'address4' where c1 = 103");
    // mysql_query(&mysql, "select * from tmptab");
    // printf("--更新数据测试--\n");
    // printResult(&mysql);
    // mysql_query(&mysql, "delete from tmptab");
    // mysql_query(&mysql, "select * from tmptab");
    // printf("--清空数据测试--\n");
    // printResult(&mysql);
    // mysql_query(&mysql, "drop table tmptab");    
    // mysql_query(&mysql, "drop database tmpdb");
    // mysql_close(&mysql);

    // 选择题
    if (type == 1)
    {
        mysql_query(&mysql, "select * from choice_question");

    }
    // 填空题
    else if (type == 2)
    {
        mysql_query(&mysql, "select * from fill_blank_question");
    }
    else
    {
        mysql_query(&mysql, "select * from choice_question");
    }
    // printf("--查询到的题目--\n");
    printResult(&mysql, buf);
}

int findTeacherById(int id, char buf[])
{
    MYSQL mysql;
    MYSQL_RES * result;
    mysql_init(&mysql);
    mysql_real_connect(&mysql, "localhost", "root", "qjp123MS..", NULL, 3306, NULL, 0); 
    mysql_query(&mysql, "set names 'utf8'");
    mysql_query(&mysql, "use exam");
    // char selectTeacherById[80] = "select teacherPassword from teacher where teacherId = ";
    char selectTeacherById[80] = {0};
    sprintf(selectTeacherById,"%s%d%s", "select * from teacher where teacherId = '", id, "'");
    // printf("%s\n", selectTeacherById);
    mysql_query(&mysql, selectTeacherById);

    int numFields = 0;
    int numRows = 0;
    MYSQL_FIELD * field;
    MYSQL_ROW row;
    int i = 0;
    result = mysql_store_result(&mysql);//将查询的全部结果读取到客户端
    numFields = mysql_num_fields(result);//统计结果集中的字段数
    numRows = mysql_num_rows(result);//统计结果集的行数
    while(field = mysql_fetch_field(result))//返回结果集中的列信息(字段)
        printf("%s\t", field->name);
    printf("\n");
    if(result)
    {
        while(row = mysql_fetch_row(result))//返回结果集中行的记录
        {
            // for(i = 1; i < numFields; i++)
            // {
                printf("%s\t", row[1]);
                strcat(buf, row[1]);
            // }
            printf("\n");
        }
    }
    mysql_free_result(result);//释放result空间，避免内存泄漏
}

int findStudentById(int id, char buf[])
{
    MYSQL mysql;
    MYSQL_RES * result;
    mysql_init(&mysql);
    mysql_real_connect(&mysql, "localhost", "root", "qjp123MS..", NULL, 3306, NULL, 0); 
    mysql_query(&mysql, "set names 'utf8'");
    mysql_query(&mysql, "use exam");
    // char selectTeacherById[80] = "select teacherPassword from teacher where teacherId = ";
    char selectStudentById[80] = {0};
    sprintf(selectStudentById,"%s%d%s", "select * from student where studentId = '", id, "'");
    // printf("%s\n", selectTeacherById);
    mysql_query(&mysql, selectStudentById);

    int numFields = 0;
    int numRows = 0;
    MYSQL_FIELD * field;
    MYSQL_ROW row;
    int i = 0;
    result = mysql_store_result(&mysql);//将查询的全部结果读取到客户端
    numFields = mysql_num_fields(result);//统计结果集中的字段数
    numRows = mysql_num_rows(result);//统计结果集的行数
    while(field = mysql_fetch_field(result))//返回结果集中的列信息(字段)
        printf("%s\t", field->name);
    printf("\n");
    if(result)
    {
        while(row = mysql_fetch_row(result))//返回结果集中行的记录
        {
            // for(i = 1; i < numFields; i++)
            // {
                printf("%s\t", row[1]);
                strcat(buf, row[1]);
            // }
            printf("\n");
        }
    }
    mysql_free_result(result);//释放result空间，避免内存泄漏
}

void updateStudentById(int id, char password[])
{
    MYSQL mysql;
    MYSQL_RES * result;
    mysql_init(&mysql);
    mysql_real_connect(&mysql, "localhost", "root", "qjp123MS..", NULL, 3306, NULL, 0); 
    mysql_query(&mysql, "set names 'utf8'");
    mysql_query(&mysql, "use exam");
    // char selectTeacherById[80] = "select teacherPassword from teacher where teacherId = ";
    char selectStudentById[80] = {0};
    sprintf(selectStudentById,"%s%s%s%d%s", "update student set studentPassword='", password, "' where studentId = '", id, "'");
    // printf("%s\n", selectTeacherById);
    mysql_query(&mysql, selectStudentById);
}

void updateTeacherById(int id, char password[])
{
    MYSQL mysql;
    MYSQL_RES * result;
    mysql_init(&mysql);
    mysql_real_connect(&mysql, "localhost", "root", "qjp123MS..", NULL, 3306, NULL, 0); 
    mysql_query(&mysql, "set names 'utf8'");
    mysql_query(&mysql, "use exam");
    // char selectTeacherById[80] = "select teacherPassword from teacher where teacherId = ";
    char selectTeacherById[80] = {0};
    sprintf(selectTeacherById,"%s%s%s%d%s", "update teacher set teacherPassword='", password, "' where teacherId = '", id, "'");
    printf("%s\n", selectTeacherById);
    mysql_query(&mysql, selectTeacherById);
}

void printResult(MYSQL *mysqlPrint, char buf[])//打印结果集(此处传入指针，而非内容)
{
    MYSQL_RES * result;
    int numFields = 0;
    int numRows = 0;
    MYSQL_FIELD * field;
    MYSQL_ROW row;
    int i = 0;
    result = mysql_store_result(mysqlPrint);//将查询的全部结果读取到客户端
    numFields = mysql_num_fields(result);//统计结果集中的字段数
    numRows = mysql_num_rows(result);//统计结果集的行数
    while(field = mysql_fetch_field(result))//返回结果集中的列信息(字段)
        printf("%s\t", field->name);
    printf("\n");
    if(result)
    {
        while(row = mysql_fetch_row(result))//返回结果集中行的记录
        {
            for(i = 0; i < numFields; i++)
            {
                printf("%s\t", row[i]);
                strcat(buf, row[i]);
                strcat(buf, "<>");
            }
            printf("\n");
            strcat(buf, "<br>");
        }
    }
    mysql_free_result(result);//释放result空间，避免内存泄漏
}

