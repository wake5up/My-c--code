//NowCoder在淘宝上开了一家网店。他发现在月份为素数的时候，当月每天能赚1元；否则每天能赚2元。
//现在给你一段时间区间，请你帮他计算总收益有多少

#include<iostream>
 
using namespace std;
 
//非闰年为标准
int totalday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//非闰年 - 每个月的总收益
int totalMoney[12] = {62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62};
 
//判断该月份是否为素数
bool Judge_IsPriNum(int month){
    if(month == 2 || month == 3 || month == 5 || month == 7 ||
          month == 11){
        return true;
    }
    return false;
}
 
//判断该年份是否为闰年
bool Judge_IsLeaYear(int year){
    if( (year % 4 == 0 && year % 100 != 0) || 
              year % 400 == 0){
        return true;
    }
    return false;
}
 
//计算相差day2 - day1天数的收益
int Caclue_Day(int day1, int day2, int month){
    //1 - 31， 是31天    31 - 1 = 30 -- 得加1
    int sum = day2 - day1 + 1;
    if(!Judge_IsPriNum(month)){
        //非素数一天赚2块
        sum += sum;
    }
    return sum;
}
 
//计算相差month2 - month1 整月数的收益
int Caclue_Month(int month1, int month2, int year){
    int sum = 0;
    for(int i = month1; i <= month2; ++i){
        //下标-1
        sum += totalMoney[i - 1];   
        //2月 - 闰年 - 多加1块
        if(i == 2 && Judge_IsLeaYear(year)){
            sum += 1;
        }
    }
    return sum;
}
 
//计算相差year2 - year1 整年数的收益
int Caclue_Year(int year1, int year2){
    int sum = 0;
    for(int i = year1; i <= year2; ++i){
        sum += Caclue_Month(1, 12, i);   
    }
    return sum;
}
 
int main(){
     
     
    //定义接受的年月日
    int year1, month1, day1;
    int year2, month2, day2;
 
    while(cin >> year1 >> month1 >> day1 
         >> year2 >> month2 >> day2){
        //由于是整数 还是 是空格分隔， 采用cin就可以
        int total_num = 0;
         
        if(year1 == year2){
            //同一年份
            if(month1 == month2){
                //同一月份     
                total_num =  Caclue_Day(day1, day2, month1);
            }
            else{
                //不同月份
                //1、先计算两者相差整月份的收益
                total_num += Caclue_Month(month1, month2, year1);
                //2、month1首月不足一月的天数收益
                total_num += Caclue_Day(day1, totalday[month1 - 1], month1);
                //3、month2尾月不足一月的天数收益
                total_num += Caclue_Day(1, day2, month2);
            }      
        }
        else{
            //不同年份
            //1、先计算两者相差整年份的收益
            total_num += Caclue_Year(year1 + 1, year2 - 1);
            //2、year1年份不足一年整月份的收益
            total_num += Caclue_Month(month1 + 1, 12, year1);
            //3、year2年份不足一年整月份的收益
            total_num += Caclue_Month(1, month2 - 1, year2);
            //4、year1中首月不足一月的收益
            total_num += Caclue_Day(day1, totalday[month1 - 1], month1);
            //5、year2中尾月不足一月的收益
            total_num += Caclue_Day(1, day2, month2); 
        }
         
        //输出
        cout << total_num << endl;
    }
}

#include<iostream>
 
using namespace std;
 
//非闰年为标准
int totalday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//非闰年 - 每个月的总收益
int totalMoney[12] = {62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62};
 
//判断该月份是否为素数
bool Judge_IsPriNum(int month){
    if(month == 2 || month == 3 || month == 5 || month == 7 ||
          month == 11){
        return true;
    }
    return false;
}
 
//判断该年份是否为闰年
bool Judge_IsLeaYear(int year){
    if( (year % 4 == 0 && year % 100 != 0) || 
              year % 400 == 0){
        return true;
    }
    return false;
}
 
//计算相差day2 - day1天数的收益
int Caclue_Day(int day1, int day2, int month){
    //1 - 31， 是31天    31 - 1 = 30 -- 得加1
    int sum = day2 - day1 + 1;
    if(!Judge_IsPriNum(month)){
        //非素数一天赚2块
        sum += sum;
    }
    return sum;
}
 
//计算相差month2 - month1 整月数的收益
int Caclue_Month(int month1, int month2, int year){
    int sum = 0;
    for(int i = month1; i <= month2; ++i){
        //下标-1
        sum += totalMoney[i - 1];   
        //2月 - 闰年 - 多加1块
        if(i == 2 && Judge_IsLeaYear(year)){
            sum += 1;
        }
    }
    return sum;
}
 
//计算相差year2 - year1 整年数的收益
int Caclue_Year(int year1, int year2){
    int sum = 0;
    for(int i = year1; i <= year2; ++i){
        sum += Caclue_Month(1, 12, i);   
    }
    return sum;
}
 
int main(){
     
     
    //定义接受的年月日
    int year1, month1, day1;
    int year2, month2, day2;
 
    while(cin >> year1 >> month1 >> day1 
         >> year2 >> month2 >> day2){
        //由于是整数 还是 是空格分隔， 采用cin就可以
        int total_num = 0;
         
        if(year1 == year2){
            //同一年份
            if(month1 == month2){
                //同一月份     
                total_num =  Caclue_Day(day1, day2, month1);
            }
            else{
                //不同月份
                //1、先计算两者相差整月份的收益
                total_num += Caclue_Month(month1, month2, year1);
                //2、month1首月不足一月的天数收益
                total_num += Caclue_Day(day1, totalday[month1 - 1], month1);
                //3、month2尾月不足一月的天数收益
                total_num += Caclue_Day(1, day2, month2);
            }      
        }
        else{
            //不同年份
            //1、先计算两者相差整年份的收益
            total_num += Caclue_Year(year1 + 1, year2 - 1);
            //2、year1年份不足一年整月份的收益
            total_num += Caclue_Month(month1 + 1, 12, year1);
            //3、year2年份不足一年整月份的收益
            total_num += Caclue_Month(1, month2 - 1, year2);
            //4、year1中首月不足一月的收益
            total_num += Caclue_Day(day1, totalday[month1 - 1], month1);
            //5、year2中尾月不足一月的收益
            total_num += Caclue_Day(1, day2, month2); 
        }
         
        //输出
        cout << total_num << endl;
    }
}

#include<iostream>
 
using namespace std;
 
//非闰年为标准
int totalday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//非闰年 - 每个月的总收益
int totalMoney[12] = {62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62};
 
//判断该月份是否为素数
bool Judge_IsPriNum(int month){
    if(month == 2 || month == 3 || month == 5 || month == 7 ||
          month == 11){
        return true;
    }
    return false;
}
 
//判断该年份是否为闰年
bool Judge_IsLeaYear(int year){
    if( (year % 4 == 0 && year % 100 != 0) || 
              year % 400 == 0){
        return true;
    }
    return false;
}
 
//计算相差day2 - day1天数的收益
int Caclue_Day(int day1, int day2, int month){
    //1 - 31， 是31天    31 - 1 = 30 -- 得加1
    int sum = day2 - day1 + 1;
    if(!Judge_IsPriNum(month)){
        //非素数一天赚2块
        sum += sum;
    }
    return sum;
}
 
//计算相差month2 - month1 整月数的收益
int Caclue_Month(int month1, int month2, int year){
    int sum = 0;
    for(int i = month1; i <= month2; ++i){
        //下标-1
        sum += totalMoney[i - 1];   
        //2月 - 闰年 - 多加1块
        if(i == 2 && Judge_IsLeaYear(year)){
            sum += 1;
        }
    }
    return sum;
}
 
//计算相差year2 - year1 整年数的收益
int Caclue_Year(int year1, int year2){
    int sum = 0;
    for(int i = year1; i <= year2; ++i){
        sum += Caclue_Month(1, 12, i);   
    }
    return sum;
}
 
int main(){
     
     
    //定义接受的年月日
    int year1, month1, day1;
    int year2, month2, day2;
 
    while(cin >> year1 >> month1 >> day1 
         >> year2 >> month2 >> day2){
        //由于是整数 还是 是空格分隔， 采用cin就可以
        int total_num = 0;
         
        if(year1 == year2){
            //同一年份
            if(month1 == month2){
                //同一月份     
                total_num =  Caclue_Day(day1, day2, month1);
            }
            else{
                //不同月份
                //1、先计算两者相差整月份的收益
                total_num += Caclue_Month(month1, month2, year1);
                //2、month1首月不足一月的天数收益
                total_num += Caclue_Day(day1, totalday[month1 - 1], month1);
                //3、month2尾月不足一月的天数收益
                total_num += Caclue_Day(1, day2, month2);
            }      
        }
        else{
            //不同年份
            //1、先计算两者相差整年份的收益
            total_num += Caclue_Year(year1 + 1, year2 - 1);
            //2、year1年份不足一年整月份的收益
            total_num += Caclue_Month(month1 + 1, 12, year1);
            //3、year2年份不足一年整月份的收益
            total_num += Caclue_Month(1, month2 - 1, year2);
            //4、year1中首月不足一月的收益
            total_num += Caclue_Day(day1, totalday[month1 - 1], month1);
            //5、year2中尾月不足一月的收益
            total_num += Caclue_Day(1, day2, month2); 
        }
         
        //输出
        cout << total_num << endl;
    }
}