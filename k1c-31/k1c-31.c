/*----------------------------------------------
IEEE754	16進→10進

2014/05/30
4I31	福嶋開人
-----------------------------------------------*/
#include<stdio.h>
#include<math.h>

#define emax 127.0//指数最大値

int main(void)
{
	unsigned int x;//いれるやつ
	int y[32];
	//s:符号	e:指数部	f:仮数部
	double  s, e = 0.0, f = 1.0;
	float answer;

	printf("IEEE754　16進→10進するプログラムです．\n\n");

	printf("8ケタの16進数を入力：");
	scanf_s("%x", &x);					//16進数入力

	//16進数を2進数に変換する．
	for (int i = 0; i < 32; i++) // IEEE単精度は32bit
	{
		if (x % 2 == 0){			//余りを代入
			y[i] = 0;
		}
		else{
			y[i] = 1;
		}
		x = x / 2;			//2で割って小さく
	}

	/*2進数を表示するのと並行して
	指数部，仮数部も計算していく*/
	printf("2進数変換:");
	for (int j = 0; j < 32; j++)//IEEE単精度は32bit
	{
		printf("%d", y[31 - j]);//2進数表示
		if ((j % 4) - 3 == 0){//見やすいように4bitごとに空白
			printf(" ");
		}

		//指数部分計算
		if (23 <= j&&j <= 30){//23bitから30bitまでの8bit
			e += y[j] * pow(2, j - 23);
		}

		//仮数部分計算
		if (j <= 22){//0bitから22bitまでの23bit
			f += y[j] * pow(2, j - 23);
		}
	}
	//符号部分計算
	s = pow(-1.0, y[31]);

	//中間報告
	printf("\n符号部：%e\n", s);
	printf("指数部：%e\n", e - emax);
	printf("仮数部：%e\n", f);

	//最終結果
	answer = s * f * pow(2, e - emax);
	printf("答え：%2.13e", answer);
	getch();

	return 0;
}