/*----------------------------------------------
IEEE754	16�i��10�i

2014/05/30
4I31	�����J�l
-----------------------------------------------*/
#include<stdio.h>
#include<math.h>

#define emax 127.0//�w���ő�l

int main(void)
{
	unsigned int x;//�������
	int y[32];
	//s:����	e:�w����	f:������
	double  s, e = 0.0, f = 1.0;
	float answer;

	printf("IEEE754�@16�i��10�i����v���O�����ł��D\n\n");

	printf("8�P�^��16�i������́F");
	scanf_s("%x", &x);					//16�i������

	//16�i����2�i���ɕϊ�����D
	for (int i = 0; i < 32; i++) // IEEE�P���x��32bit
	{
		if (x % 2 == 0){			//�]�����
			y[i] = 0;
		}
		else{
			y[i] = 1;
		}
		x = x / 2;			//2�Ŋ����ď�����
	}

	/*2�i����\������̂ƕ��s����
	�w�����C���������v�Z���Ă���*/
	printf("2�i���ϊ�:");
	for (int j = 0; j < 32; j++)//IEEE�P���x��32bit
	{
		printf("%d", y[31 - j]);//2�i���\��
		if ((j % 4) - 3 == 0){//���₷���悤��4bit���Ƃɋ�
			printf(" ");
		}

		//�w�������v�Z
		if (23 <= j&&j <= 30){//23bit����30bit�܂ł�8bit
			e += y[j] * pow(2, j - 23);
		}

		//���������v�Z
		if (j <= 22){//0bit����22bit�܂ł�23bit
			f += y[j] * pow(2, j - 23);
		}
	}
	//���������v�Z
	s = pow(-1.0, y[31]);

	//���ԕ�
	printf("\n�������F%e\n", s);
	printf("�w�����F%e\n", e - emax);
	printf("�������F%e\n", f);

	//�ŏI����
	answer = s * f * pow(2, e - emax);
	printf("�����F%2.13e", answer);
	getch();

	return 0;
}