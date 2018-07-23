char * my_strstr(char * ps,char *pd)
{
 char *pt = pd;
 int c = 0;

 while(*ps != '\0')
 {
  if(*ps == *pd)
  {
   
   while(*ps == *pd && *pd!='\0')
   {
    ps++;
    pd++;
    c++;
   }
  }

  else
  {
   ps++;

  }

  if(*pd == '\0')
  {
   //sum++;
   return (ps - c);
  }
   c = 0;
   pd = pt;
 }

 return 0;
}


/********************************************************************
*  Function：  str_replace()
*  Description: 在一个字符串中查找一个子串，并且把所有符合的子串用
                另一个替换字符串替换。
*  Calls:        memcpy();
*  Called By:    无
*  Input：      p_source:要查找的母字符串； p_seach要查找的子字符串;
                p_repstr：替换的字符串;
*  Output：      p_result:存放结果;
*  Return :      返回替换成功的子串数量;
*  Others:      p_result要足够大的空间存放结果，所以输入参数都要以\0结束;
*  date of completion: 
*********************************************************************/
int str_replace(char *p_result,char* p_source,char* p_seach,char *p_repstr)
{

 int c = 0;
 int repstr_leng = 0;
 int searchstr_leng = 0;

 char *p1;
 char *presult = p_result;
 char *psource = p_source;
 char *prep = p_repstr;
 char *pseach = p_seach;
 int nLen = 0;

 repstr_leng = strlen(prep);
 searchstr_leng = strlen(pseach);

 do{ 
  p1 = my_strstr(psource,p_seach);

  if (p1 == 0)
  {
   strcpy(presult,psource);
   return c;
  }

  c++;  //匹配子串计数加1;
  // 拷贝上一个替换点和下一个替换点中间的字符串
  nLen = p1 - psource;
  memcpy(presult, psource, nLen);

  // 拷贝需要替换的字符串
  memcpy(presult + nLen,p_repstr,repstr_leng);

  psource = p1 + searchstr_leng;
  presult = presult + nLen + repstr_leng;

 }while(p1);

 return c;

}