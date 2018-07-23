
#include "csapp.h"
#include "tools/db.c"
#include "tools/replaceStr.c"

int main(void) {
    char content[MAXLINE];
    char* buffer, *buffercp;

    /**
     * 打分
     */

    FILE * pFile;
    long lSize;
    size_t result;

    // 密码验证失败
    pFile = fopen ("../view/result.html", "rb" );

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


    /* Make the response body */
    sprintf(content, " ");
    sprintf(content, "%s\r\n", content);
    char buf[128] = {0};
    /* 10-> 数量 1->类型*/
    query(buf, 10, 1);
    // sprintf(content, "%s%d %d", content, sizeof(buffer), sizeof(buf));
    int i = str_replace(buffercp, buffer, "{xzt}", buf);
    // sprintf(content, "%s%d", content, i);
    // sprintf(content, "%s%s", content, buffercp);
    memset(buf,0,sizeof(buf));
    // memset(buffercp,0,sizeof(buffercp));
    memset(buffer,0,sizeof(buffer));
    query(buf, 10, 2);
    str_replace(buffer, buffercp, "{tkt}", buf);
    sprintf(content, "%s%s", content, buffer);


    /* Generate the HTTP response */
    printf("Connection: close\r\n");
    printf("Content-length: %d\r\n", (int)strlen(content));
    printf("Content-type: text/html\r\n\r\n");
    printf("%s", content);

    fflush(stdout);

    exit(0);
}
/* $end adder */
