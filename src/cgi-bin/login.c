#include "csapp.h"
#include "tools/replaceStr.c"
#include "tools/db.c"


/*
 学生ID < 10000
 老师ID > 10000

*/

int main(void)
{
    char *buf, *query, *env, *p1, *p2, *p3, *p4, *p5;
    char arg1[MAXLINE], arg2[MAXLINE], arg3[MAXLINE], content[MAXLINE], postdata[MAXLINE], *lenstr;
    long len=0;
    char* buffer;
    char* buffercp;
    /* 提取两个参数  */
    query = getenv("QUERY_STRING");
    if (query == NULL) {
        if ((lenstr = getenv("CONTENT_LENGTH")) != NULL)
            len = atol(lenstr);
        fgets(postdata, len+1, stdin);
        buf = postdata;
    }
    else
        buf = query;

    p1 = strchr(buf, '&');
    *p1 = '\0';

    /* 提取Name */
    p2 = strchr(buf, '=');
    *p2 = '\0';
    strcpy(arg1, p2+1);

    /* 提取Password */
    // p3 = strchr(p1+1, '=');
    p3 = strchr(p1+1, '&');
    *p3 = '\0';
    p4 = strchr(p1+1, '=');
    *p4 = '\0';
    strcpy(arg2, p4+1);

    /* 用户类别 */
    p5 = strchr(p3+1, '=');
    *p5 = '\0';
    strcpy(arg3, p5+1);

    FILE * pFile;
    long lSize;
    size_t result;
    // 密码验证成功，返回个人中心
    char password[32];

    if (!strcmp(arg3, "teacher"))
    {
        findTeacherById(atoi(arg1), password);
    }
    else if(!strcmp(arg3, "student"))
    {
        findStudentById(atoi(arg1), password);
    }

    if (!strcmp(arg2, password))
    {
        /* 若要一个byte不漏地读入整个文件，只能采用二进制方式打开 */ 
        pFile = fopen ("../view/profile.html", "rb" );

    }
    // 密码验证失败
    else
    {
        pFile = fopen ("../view/login.html", "rb" );
        sprintf(content, "%s", "密码不对");

    }

    if (pFile==NULL)
    {
        fputs ("File error",stderr);
        exit (1);
    }

    /* 获取文件大小 */
    fseek (pFile , 0 , SEEK_END);
    lSize = ftell (pFile);
    rewind (pFile);

    /* 分配内存存储整个文件 */ 
    buffer = (char*) malloc (sizeof(char)*lSize);
    buffercp = (char*) malloc (sizeof(char)*lSize);
    if (buffer == NULL || buffercp == NULL)
    {
        fputs ("Memory error",stderr); 
        exit (2);
    }

    /* 将文件拷贝到buffer中 */
    result = fread (buffer,1,lSize,pFile);
    if (result != lSize)
    {
        fputs ("Reading error",stderr);
        exit (3);
    }

    /* 现在整个文件已经在buffer中，可由标准输出打印内容 */
    /* 生成响应主体 */
    int i = str_replace(buffercp, buffer, "{ID}", arg1);
    sprintf(content, "%s%s", content, buffercp);

    /* 生成HTTP响应 */
    printf("Content-length: %d\r\n", (int)strlen(content));
    printf("Content-type: text/html\r\n\r\n");
    printf("%s", content);
    fflush(stdout);
    fclose (pFile);
    free (buffer);
    free (buffercp);
    exit(0);
}
