/*26-05-10 12:37
求两个超长正整数的和,如100个1+100个2
思路：用数组实现
 1 数据的输入：用cin不嫩保存数据，这里考虑用获取一个字符函数getchar(),只有不安回车键，就连续可以输入
 2 数据的保存：每输入一个字符就进行保存，记住输入的可是字符型，咋办，用字符的ASCII关系进行解决，
 字符'0'的ASCII为整数的48,比如获取一个字符1,'1'=49,'1'-'0'=1,这样就把他转换为了整数了，然后保存在数
 组中，从0开始，一位一位往后推，这样高位就在前，低位在后了，这样久保证个位和十位分别可以相加了 
  
 3 逻辑加：两个数进行相加可能会有进位，如何解决，把相加的两数除以10(加法中进位只会大于10)保存于一变
 量中，在对相加的数取模保存个位，最后，把个位和进位相加，还有就是怎样保证个位和个位加，十位和十位加
 ，这就要利用数组下标进行计算了 
 4 和数的保存：最后保存存在一个问题，数组长度够长，而输入的数字没有完全占用完，还有些空余的怎么处理
 这就要算出数组的长度 
*/
#include<iostream>

using namespace std;
int main()
{
    int a[200] ={0} ;  //保存加数 
    int b[200] = {0};  //保存被加数 
    //i=1，j=1,? 因为最后一位进位要一个字节空间，这里特意留的第一个空间不保存加数和别加数 
    int i=1,j=1,k=0;   
    
    int result = 0;    //保存进位后的值 
    int g;              //标志数组a[0],b[0]是否为非空 
    
    cout<<"根据提示输入正整数，输入字母程序将会中止退出！   "<<endl;
    cout<<"请输入加数  ："; 
    
	
    while ( (a[i]=getchar()) != 10 )    
    {
          if ( (a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z') )
          {
              exit(0);
          }
          else
          {
              a[i] = a[i]-'0';    //这里就用到ASCII 码的技巧，把字符很好的转换成了整形值然后保存整形
                                  //数组 
              i++;
          }
    }
    
    cout<<"请输入被加数："; 
    while ( (b[j]=getchar()) !=10 )
    {
          if ( (b[j]>='a' && b[j]<='z') || (b[j]>='A' && b[j]<='Z') ) 
          {
               exit(1);
          }
          else
          {
              b[j] = b[j]-'0';
              j++;
          }
    }
 /*
   这里用到了一个技巧，没有定义保存计算后和的数组，而是直接利用了保存加数和被加数的数组
   当然，输入两数，他们的长度可能不同,这里当然以数据长的那一个数组作为标准了 
   如果加数的位数长于被加数，则把和值保存在加数的数组中，否则相反了 
 */  
    
    if (i>=j)     //数组a的长度大于或等于数组b的长度 
    {
        k = i;
        for (; j>0; )
        {
         /*a保存的是12，b是2 结果是14
         1. result = 14/10=1 ，a[k-1](i最末的哪一位)=4  ，a和b数组下标都自减1 这时它和下面的 a[k-1]
         就不是同一值了，，result和a[k-1]加不对啊，但要知道，除10它的位置就是向高位进一位了哦 
          
         */ 
                result  = (a[k-1]+b[j-1])/10; 
                a[k-1]  = (a[k-1]+b[j-1])%10;
                k--;
                j--;
                a[k-1]  = a[k-1]+ result; 
        }
          
          if (a[0]==0)
          {
              g=1;
          }
          else
          {
              g=0;
          }
        cout<<"两数相加结果为：";
        
        /*  和的保存和加数被加数是一样的，即位数大的保存在数组低位，但是有一点，数组a[0]是空的，
        有时你输入的数相加后最后一位没进位，那它同样会输出一个0,这里既有用g作为标准了 
        */ 
        for ( int h=g; h<i; h++ )
        {
            cout<<a[h]; 
        }
        cout<<endl;
    }
    
     
    else  //数组a的长度大小于数组b的长度 ，这时以b数组作为相加后和的保存数组 
    {
        k=j;
        for (; i>0; )
        {
            result  = (a[i-1]+b[k-1])/10;
            b[k-1]  = (a[i-1]+b[k-1])%10;
            k--;
            i--;
            b[k-1]  = b[k-1]+ result; 
        }
        if (b[0]==0)
          {
              g=1;
          }
          else
          {
              g=0;
          }
         
        cout<<"两数相加结果为：";
        for ( int h=g; h<j; h++ )
        {
            cout<<b[h]; 
        }
        cout<<endl;
    }
        
    system("pause");
    return 0;
}
