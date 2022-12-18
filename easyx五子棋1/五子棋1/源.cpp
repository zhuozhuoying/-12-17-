#include<stdio.h>
#include<easyx.h>
#include<string.h>
int pve = 0, pvp = 0;//ģʽ�����жϣ����������ʱ����ʱ��ֵ�������ж�ʹ��ʲôģʽ
int location(short,short); 
int locationx(short x, short y);
int locationy(short x, short y);
int roln; int linen;  int startx, starty, abheight, ablength; wchar_t s1[10]; wchar_t s2[10];
char answhite[50][50]; char ansblack[50][50];//���ڼ�¼�ڰ����ӵ�λ�ã�ʵ��ʤ����ɣ�
         //int ansline(char[][50]); //�����жϺ����Ƿ������ʤ����
int answhitelineroll(int, int);
int ansblacklineroll(int, int);
int rectheight, rectlength;
int prelinen, preroln; char ret = 1;// ret��־�Ƿ�ѡ���˷������˵�
char retme = 0;//retme��־�Ƿ�
char memorynum[20][20][2]; int memorynumk = 1; // memorynum��ǰ������������λ�ã����һ����0�Ǻ�ɫ��1�ǰ�ɫ��


int main() {
	
	memset(memorynum, 0, sizeof(memorynum));
	while (true) {
		pvp = 0; pve = 0; ret = 0 ; retme = 0;
		cleardevice;
		memset(answhite, 0, sizeof(answhite));
		memset(ansblack, 0, sizeof(ansblack));
		//ret = 0; //�����˵����ر�־����(��0)��������һ�η���
		initgraph(1200, 800, EX_SHOWCONSOLE);//easyx ���ƴ��� EX_SHOWCONSOLE

		IMAGE img;//����һ��ͼƬ
		loadimage(&img, TEXT("./sdulib.jpg "), 1200, 800);//��䱳��ͼƬ
		putimage(0, 0, &img);
		//�����������PVP����PVE
		setbkmode(TRANSPARENT);
		settextstyle(80, 50, TEXT("����"));
		outtextxy(100, 500, TEXT("PVP"));
		outtextxy(100, 600, TEXT("PVE"));

		settextstyle(50, 30, TEXT("����"));
		settextcolor(BLACK);
		outtextxy(400, 0, TEXT("�����弤��Ծ�"));

		settextstyle(40, 20, TEXT("����"));
		outtextxy(380, 750, TEXT("����˴��ط���һ����Ϣ"));
		
		
		HWND hwndeasyx = GetHWnd();

		double backlocationlength = getwidth();
		double backlocationheight = getheight();// ���ڻط���һ�ֶԾ�  ��δ��ʹ��

		double height = getheight();//��ȡ���ڸ߶�
		double length = getwidth();//��ȡ���ڳ���

		setlinecolor(BLACK);
		//polyline();
		setbkmode(TRANSPARENT);
		//cleardevice();
		setlinestyle(PS_SOLID, 5);
		//�������̿�ʼ
		setfillcolor(RGB(120, 220, 160));
		rectheight = 9.0 / 10 * height;  //���α߿�ĸ߶�����
		rectlength = 9.0 / 10 * length;//���α߿�ĳ�������
		//���ƾ��α߿�

		startx = 1.0 / 10 * length;
		starty = 1.0 / 10 * height;
		//׼���û��Ʋ������Ȳ����ƣ��Ƚ���ͼ�λ���ƣ�����ѡ��PVP����PVE
		//�����غ���

		ExMessage msgmod;//���������Ϣ
		while (true) {
			if (pvp == 1 || pve == 1||retme==1) break;

			if (peekmessage(&msgmod, EX_MOUSE))
			{
				switch (msgmod.message)
				{
				case WM_LBUTTONDOWN:
					if (msgmod.x >= 100 && msgmod.x <= 300 && msgmod.y <= 600 && msgmod.y >= 500)
					{
						pvp = 1;
						break;
					}
					else if (msgmod.x > 100 && msgmod.x <= 300 && msgmod.y <= 700 && msgmod.y >= 600)
					{
						pve = 1;

						return 0;
					}
					if (msgmod.x >= 388 && msgmod.x <= 811 && msgmod.y >= 747 && msgmod.y <= 781)
					{
						retme = 1;

					}

				default:
					break;
				}
			}
		}
		//ѡ������Ϣ�طź����Ϣ�طŻ���
		if (retme == 1) {

			cleardevice();
			putimage(0, 0, &img);
			fillrectangle(startx, starty, rectlength, rectheight);
			settextcolor(YELLOW);
						

			//	roln���е����� ��linen���е�����
			for (int i = 1; i < preroln; i++) {
				line(startx + i * ablength / preroln, starty, startx + i * ablength / preroln, rectheight);//�����ֱ�Ϊ ��ʼ���x��y ��ֹ���x��y
				
			}
			//line(startx + (roln) * ablength / roln, starty, startx + (roln) * ablength / roln, rectheight);
			//���ƺ���ֱ��
			for (int i = 1; i < prelinen; i++) {
				line(startx, starty + i * abheight / prelinen, rectlength, starty + i * abheight / prelinen);
			}
			for(int i=0;i<=preroln;i++)
			{ 
				for(int j=0;j<=prelinen;j++)
				{   //0�Ǻ�ɫ��1�ǰ�ɫ
					if (memorynum[i][j][0] >0) 
					{
						setfillcolor(BLACK);
						solidcircle(startx+i*ablength/preroln,starty+j*abheight/prelinen, (ablength / (2.5 * roln)) < abheight / (2.5 * linen) ? (ablength / (2.5 * roln)) : (abheight / (2.5 * linen)));
						//outtextxy(startx + i * ablength / preroln, starty + j * abheight / prelinen, TEXT("memorynum[i][j][0]"));
						settextcolor(RED);
						RECT r = { startx + i * ablength - (ablength / (2.5 * roln)) < abheight / (2.5 * linen) ? (ablength / (2.5 * roln)) : (abheight / (2.5 * linen)),starty + j * abheight / prelinen + (ablength / (2.5 * roln)) < abheight / (2.5 * linen) ? (ablength / (2.5 * roln)) : (abheight / (2.5 * linen)),startx + i * ablength + (ablength / (2.5 * roln)) < abheight / (2.5 * linen) ? (ablength / (2.5 * roln)) : (abheight / (2.5 * linen)),starty + j * abheight / prelinen - (ablength / (2.5 * roln)) < abheight / (2.5 * linen) ? (ablength / (2.5 * roln)) : (abheight / (2.5 * linen)) };
						drawtext(memorynum[i][j][0], &r, DT_SINGLELINE);
					}
					else if(memorynum[i][j][1]>0)
					{
						setfillcolor(WHITE);
						solidcircle(startx + i * ablength / preroln, starty + j * abheight / prelinen, (ablength / (2.5 * roln)) < abheight / (2.5 * linen) ? (ablength / (2.5 * roln)) : (abheight / (2.5 * linen)));
					
					}
				}
			}
			//	memorynum[(locationx(msg.x, msg.y) - startx) * preroln / ablength][(locationy(msg.x, msg.y) - starty) * prelinen / abheight][1] 
			while (true) {

			}




			
		}



		//���ƶ�ս��������
		cleardevice();
		putimage(0, 0, &img);
		fillrectangle(startx, starty, rectlength, rectheight);//���ƾ������̿��ĸ������ֱ��Ӧ�� x ���꣬���� y ���꣬�Ҳ� x ���꣬�ײ� y ����
		//��������ֱ��
		abheight = rectheight - starty;//���θ߶�
		ablength = rectlength - startx;//���γ���

		memset(s1, 0, sizeof(s1));    memset(s2, 0, sizeof(s2));
		InputBox(s1, 10, TEXT("����������"));
		InputBox(s2, 10, TEXT("����������"));

		linen = _wtoi(s1);  // ������ת��Ϊ����
		roln = _wtoi(s2);
		prelinen = linen - 1;
		preroln = roln - 1;
		

		//	roln���е����� ��linen���е�����
		for (int i = 1; i < preroln; i++) {
			line(startx + i * ablength / preroln, starty, startx + i * ablength / preroln, rectheight);//�����ֱ�Ϊ ��ʼ���x��y ��ֹ���x��y
		}
		//line(startx + (roln) * ablength / roln, starty, startx + (roln) * ablength / roln, rectheight);
		//���ƺ���ֱ��
		for (int i = 1; i < prelinen; i++) {
			line(startx, starty + i * abheight / prelinen, rectlength, starty + i * abheight / prelinen);
		}

		//�������̽���

		//�����Ϣ�Ľ����жϿ�ʼ
		if (pvp == 1) {

			ExMessage msg; //ExMessage�����ı��� ���ڱ��������Ϣ msg�п��Ա����������Ұ�����Ϣ�����Ի�ȡ���������Ϣ��������Ϣ�ȵ�
			while (ret==0) {
				
				
				if (peekmessage(&msg, EX_MOUSE))
				{
				//	printf("x:%d\n", msg.x);
			//		printf("y:%d\n", msg.y);
					switch (msg.message)
					{
					case WM_LBUTTONDOWN:
						if (location(msg.x, msg.y))  //�ж��Ƿ����߽��㸽��
						{
							//		printf(":x������Ϊ��%d:\n", (locationx(msg.x, msg.y) - startx) * preroln / ablength);
							//			printf(":y������Ϊ��%d:\n", (locationy(msg.x, msg.y) - starty) * prelinen / abheight);
							//			printf("%d\n", locationx(msg.x, msg.y));
							//			printf("%d\n", locationy(msg.x, msg.y));
							if (getfillcolor() == WHITE)
							{
								setfillcolor(BLACK);
								if (ansblack[(locationx(msg.x, msg.y) - startx) * preroln / ablength][int((locationy(msg.x, msg.y) - starty) * prelinen / abheight)] == 0 && answhite[(locationx(msg.x, msg.y) - startx) * preroln / ablength][(locationy(msg.x, msg.y) - starty) * prelinen / abheight] == 0 && ((locationx(msg.x, msg.y) - startx) * preroln / ablength != -1) && ((locationy(msg.x, msg.y) - starty) * prelinen / abheight != -1))//if (ansblack[int((locationx(msg.x, msg.y) - startx) * preroln / ablength) / ablength][int((locationy(msg.x, msg.y) - starty) * prelinen / abheight)] == 0 && answhite[int((locationx(msg.x, msg.y) - startx) * preroln / ablength)][int ((locationy(msg.x, msg.y) - starty) * prelinen / abheight)] == 0)
								{	//���ƺڰ�����

									solidcircle(locationx(msg.x, msg.y), locationy(msg.x, msg.y), (ablength / (2.5 * roln)) < abheight / (2.5 * linen) ? (ablength / (2.5 * roln)) : (abheight / (2.5 * linen)));
									//��¼�ڰ���������˳��
									ansblack[(locationx(msg.x, msg.y) - startx) * preroln / ablength][(locationy(msg.x, msg.y) - starty) * prelinen / abheight] = 1;
									memorynum[(locationx(msg.x, msg.y) - startx) * preroln / ablength][(locationy(msg.x, msg.y) - starty) * prelinen / abheight][0] = memorynumk;//0�Ǻ�ɫ��1�ǰ�ɫ
									memorynumk++;

								}
								else {
									setfillcolor(WHITE);


								}
							}
							else
							{
								setfillcolor(WHITE);
								if (ansblack[(locationx(msg.x, msg.y) - startx) * preroln / ablength][(locationy(msg.x, msg.y) - starty) * prelinen / abheight] == 0 && answhite[(locationx(msg.x, msg.y) - startx) * preroln / ablength][(locationy(msg.x, msg.y) - starty) * prelinen / abheight] == 0 && ((locationx(msg.x, msg.y) - startx) * preroln / ablength != -1) && ((locationy(msg.x, msg.y) - starty) * prelinen / abheight != -1))//if (ansblack[roln * locationx(msg.x, msg.y) / rectlength][linen * locationy(msg.x, msg.y) / rectheight] == 0 && answhite[roln * locationx(msg.x, msg.y) / rectlength][linen * locationy(msg.x, msg.y) / rectheight] == 0)
								{	//���ƺڰ�����
									solidcircle(locationx(msg.x, msg.y), locationy(msg.x, msg.y), (ablength / (2.5 * roln)) < abheight / (2.5 * linen) ? (ablength / (2.5 * roln)) : (abheight / (2.5 * linen)));
									//��¼�ڰ���������˳��
									answhite[(locationx(msg.x, msg.y) - startx) * preroln / ablength][(locationy(msg.x, msg.y) - starty) * prelinen / abheight] = 1;
									memorynum[(locationx(msg.x, msg.y) - startx) * preroln / ablength][(locationy(msg.x, msg.y) - starty) * prelinen / abheight][1] = memorynumk;
									memorynumk++;
								}
								else
								{
									setfillcolor(BLACK);


								}
							}

							//��ʤ�ж�
							if (answhitelineroll(((locationx(msg.x, msg.y) - startx) * preroln / ablength), ((locationy(msg.x, msg.y) - starty) * prelinen / abheight)))
							{
								
								if (MessageBox(hwndeasyx, TEXT("��ϲ�������ʤ�����ȷ��������ҳ�棡���ȡ���˳�"), TEXT("�Ծֽ���"), MB_YESNO) == IDYES) {
									ret=1;
									break;
								}
								else
								{

									closegraph;
									return 0;
								}
							}

							if (ansblacklineroll(((locationx(msg.x, msg.y) - startx) * preroln / ablength), ((locationy(msg.x, msg.y) - starty) * prelinen / abheight)))//(ansblacklineroll((roln * locationx(msg.x, msg.y) / rectlength), (linen * locationy(msg.x, msg.y) / rectheight)))
							{
								if (MessageBox(hwndeasyx, TEXT("��ϲ�������ʤ�����ȡ���˳���"), TEXT("�Ծֽ���"), MB_YESNO) == IDYES) {
									ret=1;
									
								}
								else {

									closegraph;
									return 0;
								}
							}
					







							break;
						}
				

					


					default:
						break;
					}
				}
			}
			//�����Ϣ�Ľ����жϽ���  �ڶ�while����
		


		}
		else if (pve == 1) {











		}




	

}



MessageBox(NULL, TEXT("��Һã�"), TEXT("I LOVE YOU "), MB_OK);
	getchar();
	closegraph();
}



//�ж���������Ƿ������̽���
int location(short x,short y ) {
	for (int i = 0; i < prelinen+1 ; i++) {     
		for (int j = 0; j < preroln+1; j++) {   
			if(x< startx + j * ablength / preroln +ablength/(3*preroln) 
				&& x>startx + j * ablength / preroln -ablength/(3*preroln) 
				&& y< starty + i * abheight / prelinen + abheight/(3*prelinen)
				&& y>starty + i * abheight / prelinen - abheight / (3* prelinen) )
			{
				return 1;
			}
		}

	}
	return NULL;

}
//���轻��λ��  x����λ��
int locationx(short x, short y) {
	for (int i = 0; i < linen+1 ; i++) {
		for (int j = 0; j < roln+1 ; j++) {
			if (x< startx + j * ablength / preroln + ablength / (3 * roln)
				&& x>startx + j * ablength / preroln - ablength / (3 * roln)
				&& y< starty + i * abheight / prelinen + abheight / (3 * linen)
				&& y>starty + i * abheight / prelinen - abheight / (3 * linen))
			{
				return 1+startx + j * ablength / preroln;
			}
		}

	}
}
//���轻��λ�� y����λ��
int locationy(short x, short y) {
	for (int i = 0; i < linen+1 ; i++) {
		for (int j = 0; j < roln+1 ; j++) {
			if (x< startx + j * ablength / preroln + ablength / (3 * roln)
				&& x>startx + j * ablength / preroln - ablength / (3* roln)
				&& y< starty + i * abheight / prelinen + abheight / (3 * linen)
				&& y>starty + i * abheight /prelinen - abheight / (3 * linen))
			{
				return 1+starty + i * abheight / prelinen;
			}
		}

	}


}


  //ʤ�������ж�
  //�ж��������û����������������
//�ж������û�����������İ�ɫ����
int answhitelineroll(int x, int y) {
	
	for (int i = 0; i + 4 <= roln; i++) {
		int sum = 0;
		sum = answhite[i][y] + answhite[i + 1][y] + answhite[i + 2][y] + answhite[i + 3][y] + answhite[i + 4][y];
		if (sum == 5) return 1;
	}
	for(int i=0;i+4<=linen;i++)
	{
		int sum = 0;
		sum = answhite[x][i] + answhite[x][i + 1] + answhite[x][i + 2] + answhite[x][i + 3] + answhite[x][i + 4];
		if (sum == 5) return 1;
	}

	//���������µ����ϵ��ж�
	int xnw = x, ynw = y;
	while (xnw > 0 && ynw <=linen) {
		xnw--; ynw++;
	}

	while (xnw + 4 <= roln && ynw -4 >=0 ) {

		int sum = 0;
		sum = answhite[xnw][ynw] + answhite[xnw + 1][ynw - 1] + answhite[xnw + 2][ynw - 2] + answhite[xnw + 3][ynw - 3] + answhite[xnw + 4][ynw - 4];
		if (sum == 5)
		{
			
			return 1;
		}
		xnw++; ynw--;
	}



	//int xnw = x, ynw = y;
	//while (xnw-4 >= 0 && xnw+4 <= roln && ynw-4 >= 0 && ynw+4 <= roln)
	//{
	//	int sum = 0;
	//	sum = answhite[xnw][ynw] + answhite[xnw - 1][ynw - 1] + answhite[xnw - 2][ynw - 2] + answhite[xnw - 3][ynw - 3] + answhite[xnw - 4][ynw - 4];
//		if (sum == 5) return 1;
//		xnw--; ynw--;

//	}
	//xnw = x, ynw = y;
//	while (xnw - 4 >= 0 && xnw + 4 <= roln && ynw - 4 >= 0 && ynw + 4 <= roln)
//	{
//		int sum = 0;
//		sum = answhite[xnw][ynw] + answhite[xnw + 1][ynw + 1] + answhite[xnw + 2][ynw + 2] + answhite[xnw + 3][ynw + 3] + answhite[xnw + 4][ynw + 4];
//		if (sum == 5) return 1;
//		xnw++; ynw++;

//	}
	
	//���������ϵ����µ��ж�
	xnw = x; ynw = y;
	while (xnw  > 0 && ynw  > 0) {
		xnw--; ynw--;
	}
	
	while (xnw + 4 <= roln && ynw + 4 <= linen) {
		int sum = 0;
		sum = answhite[xnw][ynw] + answhite[xnw + 1][ynw + 1] + answhite[xnw + 2][ynw + 2] + answhite[xnw + 3][ynw + 3] + answhite[xnw + 4][ynw + 4];
		if (sum == 5) return 1;
		
		xnw++; ynw++;
	}
	//while (xnw - 4 >= 0 && xnw + 4 <= roln && ynw - 4 >= 0 && ynw + 4 <= roln)
	//{
//		int sum = 0;
	//	sum = answhite[xnw][ynw] + answhite[xnw - 1][ynw + 1] + answhite[xnw - 2][ynw + 2] + answhite[xnw - 3][ynw + 3] + answhite[xnw - 4][ynw + 4];
	//	if (sum == 5) return 1;
//		xnw--; ynw++;

//	}
//	xnw = x, ynw = y;
//	while (xnw - 4 >= 0 && xnw + 4 <= roln && ynw - 4 >= 0 && ynw + 4 <= roln)
//	{
//		int sum = 0;
//		sum = answhite[xnw][ynw] + answhite[xnw + 1][ynw - 1] + answhite[xnw + 2][ynw - 2] + answhite[xnw + 3][ynw - 3] + answhite[xnw + 4][ynw - 4];
//		if (sum == 5) return 1;
//		xnw++; ynw--;

//	}
	return 0;
}

//�ж�����ɫ����
int ansblacklineroll(int x, int y) {

	for (int i = 0; i + 4 <= roln; i++) {
		int sum = 0;
		sum = ansblack[i][y] + ansblack[i + 1][y] + ansblack[i + 2][y] + ansblack[i + 3][y] + ansblack[i + 4][y];
		if (sum == 5) return 1;
	}

	for (int i = 0; i + 4 <= linen; i++)
	{
		int sum = 0;
		sum = ansblack[x][i] + ansblack[x][i + 1] + ansblack[x][i + 2] + ansblack[x][i + 3] + ansblack[x][i + 4];
		if (sum == 5) return 1;
	}

	//���������µ����ϵ��ж�
	int xnw = x, ynw = y;
	while (xnw > 0 && ynw <= linen) {
		xnw--; ynw++;
	}

	while (xnw + 4 <= roln && ynw - 4 >= 0) {

		int sum = 0;
		sum = ansblack[xnw][ynw] + ansblack[xnw + 1][ynw - 1] + ansblack[xnw + 2][ynw - 2] + ansblack[xnw + 3][ynw - 3] + ansblack[xnw + 4][ynw - 4];
		if (sum == 5)
		{

			return 1;
		}
		xnw++; ynw--;
	}

	//���������ϵ����µ��ж�
	xnw = x; ynw = y;
	while (xnw > 0 && ynw > 0) {
		xnw--; ynw--;
	}

	while (xnw + 4 <= roln && ynw + 4 <= linen) {
		int sum = 0;
		sum = ansblack[xnw][ynw] + ansblack[xnw + 1][ynw + 1] + ansblack[xnw + 2][ynw + 2] + ansblack[xnw + 3][ynw + 3] + ansblack[xnw + 4][ynw + 4];
		if (sum == 5) return 1;

		xnw++; ynw++;
	}
	
	return 0;
}
//ʤ�������жϽ���


