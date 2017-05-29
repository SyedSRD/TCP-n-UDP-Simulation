#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<GL/glut.h>

float x0,y0,x1,y1,gx,xra0,xra1;

void delay(float k) {
	for (int h = 0; h < k*700000000; h++)
		;
}

void bitmap(int x, int y, char *string, void*font)
{
	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i<len; i++)
	{
		glutBitmapCharacter(font, string[i]);
	}

}

void writeTop(char *str, int a,float f=1.0) {

	if (a == 1 || a == 3) {
		glColor3f(0, 1, 1);
		bitmap(350, 730, str, GLUT_BITMAP_TIMES_ROMAN_24);
		glFlush();
		delay(f);
	}
	if (a == 2 || a == 3) {
		glColor3f(0, 0, 0);
		bitmap(350, 730, str, GLUT_BITMAP_TIMES_ROMAN_24);
	}


}

void writeBop(char *str, int a,int x=150) {

	if (a == 1 ) {
		glColor3f(1, 0, 1);
		bitmap(x, 60, str, GLUT_BITMAP_HELVETICA_18);
		glFlush();
		//delay(1);
	}
	if (a == 2) {
		glColor3f(0, 0, 0);
		bitmap(x, 60, str, GLUT_BITMAP_HELVETICA_18);
	}


}

void create(char *sta,float f=1.0) {
	int k = 0;
	writeTop(sta, 2);
	writeBop("Press a to create socket for server A else b for server B ", 2);
	printf("Connecting to local server A with port address %d\n", 65635 % rand());
	printf("Connecting...\n\n");
	delay(0.2);
	while (k++ < 3) {
		writeTop("CONNECTING.", 3,f);
		writeTop("CONNECTING..", 3,f);
		writeTop("CONNECTING...", 3,f);
	}

}
void packet(float x0 ,float y0 ,float x1 ,float y1) {
	float xd = 50;
	int k = 0;
	if ((gx != 1 && y0 == 655) || (gx != 2 && y0 == 125)) //for unorderd packet transform
		return;
	writeTop("READY...", 2);
	
	while (k++ < 3) {
		writeTop("LOADING.", 3,0.5);
		writeTop("LOADING..", 3,0.5);
		writeTop("LOADING...", 3,0.5);
	}
	writeTop("SENDING...", 1);
	for (; x0 < 500;) {
		
		glBegin(GL_POLYGON);
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(x0 + 2*xd, y0);
		glVertex2f(x0 + 2*xd, y1);
		glVertex2f(x1 + 2*xd, y1);
		glVertex2f(x1 + 2*xd, y0);
		glEnd();
		glFlush();

		Sleep(0.5);

		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(x0 + 2*xd, y0);
		glVertex2f(x0 + 2*xd, y1);
		glVertex2f(x1 + 2*xd, y1);
		glVertex2f(x1 + 2*xd, y0);
		glEnd();


		glBegin(GL_POLYGON);
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(x0 + xd, y0);
		glVertex2f(x0 + xd, y1);
		glVertex2f(x1 + xd, y1);
		glVertex2f(x1 + xd, y0);
		glEnd();
		glFlush();
		
		Sleep(0.5);

		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(x0 + xd, y0);
		glVertex2f(x0 + xd, y1);
		glVertex2f(x1 + xd, y1);
		glVertex2f(x1 + xd, y0);
		glEnd();
		

		glBegin(GL_POLYGON);
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(x0, y0);
		glVertex2f(x0, y1);
		glVertex2f(x1, y1);
		glVertex2f(x1, y0);
		glEnd();
		glFlush();
		
		Sleep(0.5);
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(x0, y0);
		glVertex2f(x0, y1);
		glVertex2f(x1, y1);
		glVertex2f(x1, y0);
		glEnd();
		
		x0 += 0.2;
		x1 += 0.2;
	}
	writeTop("SENDING...", 2);
	printf("Your data is successfully delivered....\n");
	writeTop("CLOSING", 1);
	printf("Closing...\n");
	delay(2);
	writeTop("CLOSING", 2);
	gx = 0;

}

void request() {
	xra0 = 110, xra1 = 130;

	for(;xra1<620;){
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(xra0, 387);
	glVertex2f(xra0, 410);
	glVertex2f(xra1, 410);
	glVertex2f(xra1, 387);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(xra0, 387);
	glVertex2f(xra0, 410);
	glVertex2f(xra1, 410);
	glVertex2f(xra1, 387);
	glEnd();

	xra0 += 0.1;
	xra1 += 0.1;
}

}

void acknowledg() {
	xra0 = 590, xra1 = 620;

	for (; xra1>130;) {
		glBegin(GL_POLYGON);
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(xra0, 387);
		glVertex2f(xra0, 410);
		glVertex2f(xra1, 410);
		glVertex2f(xra1, 387);
		glEnd();
		glFlush();

		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(xra0, 387);
		glVertex2f(xra0, 410);
		glVertex2f(xra1, 410);
		glVertex2f(xra1, 387);
		glEnd();

		xra0 -= 0.1;
		xra1 -= 0.1;
	}

}

void tunnel1() {

	glColor3f(1, 0, 0);

	glBegin(GL_LINES);
	glVertex2f(100.0, 400.0);
	glVertex2f(200.0, 650.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(100.0, 400.0);
	glVertex2f(200.0, 680.0);
	glEnd();

	//socket
	glBegin(GL_LINES);
	glVertex2f(200.0, 650.0);
	glVertex2f(650.0, 650.0);
	glEnd();

	glTranslatef(0.0, 30.0, 0);

	glBegin(GL_LINES);
	glVertex2f(200.0, 650.0);
	glVertex2f(650.0, 650.0);
	glEnd();
	
	glTranslatef(0.0, -30.0, 0);
	
}
void tunnel2() {
	glColor3f(1, 0, 0);

	glBegin(GL_LINES);
	glVertex2f(100.0, 400.0);
	glVertex2f(200.0, 150.0);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2f(100.0, 400.0);
	glVertex2f(200.0, 120.0);
	glEnd();
	
	//socket
	glBegin(GL_LINES);
	glVertex2f(200.0, 150.0);
	glVertex2f(650.0, 150.0);
	glEnd();

	glTranslatef(0.0, -30.0, 0);

	glBegin(GL_LINES);
	glVertex2f(200.0, 150.0);
	glVertex2f(650.0, 150.0);
	glEnd();
	
	glTranslatef(0.0, 30.0, 0);
	

}
void tunnel3(int r) {

	glColor3f(r, 0, 0);
	//socket
	glBegin(GL_LINES);
	glVertex2f(100.0, 380.0);
	glVertex2f(625.0, 380.0);
	glEnd();

	glTranslatef(0.0, 40.0, 0);

	glBegin(GL_LINES);
	glVertex2f(100.0, 380.0);
	glVertex2f(625.0, 380.0);
	glEnd();

	glTranslatef(0.0, -40.0, 0);

}
void pc(float xc, float yc) {
	
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.5, 0.6);
	glVertex2f(xc-10, yc-10);
	glVertex2f(xc-10, yc + 60);
	glColor3f(0.3, 0.5, 0.6);
	glVertex2f(xc + 60, yc + 60);
	glVertex2f(xc + 60, yc-10);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(xc, yc);
	glVertex2f(xc, yc + 50);
	glVertex2f(xc + 50, yc + 50);
	glVertex2f(xc + 50, yc);
	glEnd();
	glFlush();

}

void displayTCP() {

	glClear(GL_COLOR_BUFFER_BIT);
	
	pc(30, 375);
	pc(700, 640);
	pc(700, 115);
	pc(650, 375);
	
	glColor3f(1, 0, 0);
	bitmap(45, 390, "C", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap(715, 655, "A", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap(715, 130, "B", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap(665, 390, "W", GLUT_BITMAP_TIMES_ROMAN_24);
	
	writeTop("TCP SOCKET", 1);
	system("cls");
	printf("\n\n\n*******WELCOME*******\n\n\n");
	printf("You are about to create an Transmission Control Protocol socket\n");
	printf("Choose any one server to create a socket|Tunnel|Pipe\n");
	writeBop("Press a to create socket for server A else b for server B ", 1);
	
	if (gx == 1) {
		writeBop("Press a to create socket for server A else b for server B ", 2);
		tunnel3(1);
		writeTop("TCP SOCKET", 2);
		printf("Requesting port adderess from Window server...\n");
		writeTop("REQUESTING...", 1);
		delay(0.5);
		request();
		writeTop("REQUESTING...", 2);
		writeTop("ACKNOWLEDGING...", 1);
		delay(1);
		acknowledg();
		writeTop("ACKNOWLEDGING...", 2);
		printf("Acknowledgement recieved...\n");
		delay(0.5);
		tunnel3(0);
		printf("Establishing the connection for real server...\n");
		create("TCP SOCKET", 0.5);
		tunnel1();
		printf("The socket ready for data transfer\n");
		writeTop("READY...", 1);
		printf("Are you sure want to transfer data then press t else q to exit\n");
		writeBop("Press t for data transfer", 1, 300);
	}

	if (gx == 2) {
		writeBop("Press a to create socket for server A else b for server B ", 2);
		tunnel3(1);
		writeTop("TCP SOCKET", 2);
		printf("Requesting port adderess from Window server...\n");
		writeTop("REQUESTING...", 1);
		delay(0.5);
		request();
		writeTop("REQUESTING...", 2);
		writeTop("ACKNOWLEDGING...", 1);
		delay(1);
		acknowledg();
		writeTop("ACKNOWLEDGING...", 2);
		printf("Acknowledgement recieved...\n");
		delay(0.5);
		tunnel3(0);
		printf("Establishing the connection for real server...\n");
		create("TCP SOCKET", 0.5);
		tunnel2();
		printf("The socket ready for data transfer\n");
		writeTop("READY...", 1);
		printf("Are you sure want to transfer data then press d else q to exit\n");
		writeBop("Press d for data transfer", 1, 300);
	}

	glFlush();
}
void displayUDP() {
	int k = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	
	pc(30, 375);
	pc(700, 640);
	pc(700, 115);
	glColor3f(1, 0, 0);
	bitmap(45, 390, "C", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap(715, 655, "A", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap(715, 130, "B", GLUT_BITMAP_TIMES_ROMAN_24);
	writeTop("UDP SOCKET", 1);
	system("cls");
	printf("\n\n\n*******WELCOME*******\n\n\n");
	printf("You are about to create an User Datagram Protocol socket\n");
	printf("Choose any one server to create a socket|Tunnel|Pipe\n");
	
	writeBop("Press a to create socket for server A else b for server B ", 1);
	
	if (gx == 1) {
			create("UDP SOCKET");
			tunnel1();
			printf("The socket ready for data transfer\n");
			writeTop("READY...", 1);
			printf("Your are transferring data via unreliable network.\nYour data is not guaranteed to be deliver\n");
			printf("if you still want to transfer then press t else press q to exit\n\n");
			writeBop("Press t for data transfer", 1, 300);

	}

	if (gx == 2) {
		create("UDP SOCKET");
		tunnel2();
		printf("The socket ready for data transfer\n");
		writeTop("READY...", 1);
		printf("Your are transferring data via unreliable network.\nYour data is not guaranteed to be deliver\n");
		printf("if you still want to transfer then press t else press q to exit\n\n");
		writeBop("Press d for data transfer", 1, 300);
	}

	glFlush();

}
void keys(unsigned char key,int x,int y) {
	
	if (key == 'a') gx=1;
	if (key == 'b')gx=2;
	if (key == 't') writeBop("Press t for data transfer", 2, 300),packet(200, 655, 230, 675);
	if (key == 'd') writeBop("Press d for data transfer", 2, 300), packet(200, 125, 230, 145);
	if (key == 'q') exit(0);

	glutPostRedisplay();
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 799.0, 0.0, 799.0);
}
int main(int argc, char** argv)
{
	int a;
	printf("Press 1 for TCP & 2 for UDP\n");
	scanf_s("%d",&a);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(480, 0);
	glutCreateWindow("TCP & UDP");
	glutKeyboardFunc(keys);
	if (a == 1)
		glutDisplayFunc(displayTCP);
	else if (a == 2)
		glutDisplayFunc(displayUDP);

	init();
	
	glutMainLoop();

}
