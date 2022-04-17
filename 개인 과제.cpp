#include<bangtal.h>

SceneID room1, room2, room3, l1 ,l2 ,l3 ,l4 ,l5 ,l6, h1, h2, h3, h4, h5, h6, r1, r2, r3, r4, r5, r6, r7, r8, r9, finish;
ObjectID dog, button, start, restart, tree, high, low, string, gage, amount, human, stringhuman, leaf1, leaf2, key, door, restart2;
TimerID timer1,timer2, timer3, timer4, timerl1, timerl2, timerl3, timerl4, timerl5, timerl6, timerh1, timerh2, timerh3, timerh4, timerh5, timerh6, timerr1, timerr2, timerr3, timerr4, timerr5, timerr6, timerr7, timerr8, timerr9;

int dogX = 10;
int power=1;
int amountY = 420;
int num=0;

void endGame() {
	dogX = 10;
	locateObject(dog, room1, dogX, 362);
	hideObject(button);
	showObject(restart);
	hideObject(tree);
	stopTimer(timer1);
	stopTimer(timer2);
	enterScene(room1);
	hideObject(high);
	hideObject(low);
	hideObject(gage);
	hideObject(amount);
	locateObject(amount,room2, 40, 420);
	hideObject(stringhuman);
	showObject(human);
	showObject(string);
	setTimer(timer4,5.0f);
	num = 0;
	amountY = 420;
	power = 1;
	showObject(leaf1);
	showObject(leaf2);
	hideObject(key);

}

void startGame(){
	hideObject(restart);
	hideObject(start);
	showObject(button);
	startTimer(timer1);
	showMessage("다리를 건너고 건너서 집을 찾아 가세요!!!!");
}

void cha() {
	setTimer(timer2, 2.0f);
	stopTimer(timer3);
	startTimer(timer2);
	showObject(tree);
}

void chax() {
	setTimer(timer1, 2.0f);
	startTimer(timer1);
	setTimer(timer3, 0.01f);
	startTimer(timer3);
	hideObject(tree);
}

void check() {
	setTimer(timer3, 0.01f);
	startTimer(timer3);
	if ((330 < dogX && dogX < 470) || (490 < dogX && dogX < 630) || (650 < dogX && dogX < 770) || (810 < dogX && dogX < 950))
		endGame();
}




void right() {
	enterScene(r1);
	startTimer(timerr1);
}

void underwrong() {
	enterScene(l1);
	startTimer(timerl1);
}

void upwrong() {
	enterScene(h1);
	startTimer(timerh1);
}

void check2() {
	if (power == 4)
		right();
	else if (power < 4)
		underwrong();
	else
		upwrong();
}

ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown) {

	ObjectID object = createObject(image);

	locateObject(object, scene, x, y);
	if (shown) {
		showObject(object);
	}
	return object;
}

void timerCallback(TimerID timer) {
	if (timer == timer1)
		cha();
	if (timer == timer2) 
		chax();
	if (timer == timer3)
		check();

	if (timer == timer4)
		check2();
	
	if (timer == timerl1) {
		startTimer(timerl2);
		enterScene(l2);
	}
	if (timer == timerl2)
	{
		startTimer(timerl3);
		enterScene(l3);
	}
	if (timer == timerl3)
	{
		startTimer(timerl4);
		enterScene(l4);
	}
	if (timer == timerl4)
	{
		startTimer(timerl5);
		enterScene(l5);
	}
	if (timer == timerl5)
	{
		startTimer(timerl6);
		enterScene(l6);
	}
	if (timer == timerl6) {
		showMessage("약해요!");
		endGame();
	}


	if (timer == timerh1) {
		startTimer(timerh2);
		enterScene(h2);
	}
	if (timer == timerh2)
	{
		startTimer(timerh3);
		enterScene(h3);
	}
	if (timer == timerh3)
	{
		startTimer(timerh4);
		enterScene(h4);
	}
	if (timer == timerh4)
	{
		startTimer(timerh5);
		enterScene(h5);
	}
	if (timer == timerh5)
	{
		startTimer(timerh6);
		enterScene(h6);
	}
	if (timer == timerh6) {
		showMessage("강해요!");
		endGame();
	}

	if (timer == timerr1) {
		startTimer(timerr2);
		enterScene(r2);
	}
	if (timer == timerr2)
	{
		startTimer(timerr3);
		enterScene(r3);
	}
	if (timer == timerr3)
	{
		startTimer(timerr4);
		enterScene(r4);
	}
	if (timer == timerr4)
	{
		startTimer(timerr5);
		enterScene(r5);
	}
	if (timer == timerr5)
	{
		startTimer(timerr6);
		enterScene(r6);
	}
	if (timer == timerr6)
	{
		startTimer(timerr7);
		enterScene(r7);
	}
	if (timer == timerr7)
	{
		startTimer(timerr8);
		enterScene(r8);
	}
	if (timer == timerr8)
	{
		startTimer(timerr9);
		enterScene(r9);
	}
	if (timer == timerr9)
	{
		enterScene(room3);
		showMessage("숨겨진 열쇠를 찾으세요!!");
	}
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == button) {
		dogX = dogX + 20;
		locateObject(dog, room1, dogX, 362);
		if (dogX > 1000) {
			enterScene(room2);
			showMessage("길을 건널 도구를 찾으세요.");
		}
	}
	else if (object == start)
		startGame();
	else if (object == restart)
		startGame();

	else if (object == string) {
		showObject(high);
		showObject(low);
		showObject(gage);
		showObject(amount);
		showObject(stringhuman);
		hideObject(human);
		hideObject(string);
		startTimer(timer4);
		showTimer(timer4);
		showMessage("밧줄 던질 힘을 선택하세요!!!,5s");

	}
	else if (object == high) {
		if (power < 6) {
			power++;
			amountY = amountY + 42;
			locateObject(amount, room2, 40, amountY);
		}
	}
	else if (object == low) {
		if (power > 1) {
			power--;
			amountY = amountY - 42;
			locateObject(amount, room2, 40, amountY);
		}
	}
	else if (object == leaf2)
		hideObject(leaf2);
	else if (object == leaf1) {
		hideObject(leaf1);
		showObject(key);
	}
	else if (object == key) {
		hideObject(key);
		num++;
	}
	else if (object == door) {
		if (num == 1) {
			enterScene(finish);
			showMessage("도착~");
			showObject(restart2);
		}
	}
	else if (object == restart2)
		endGame();
}

int main() {
	setMouseCallback(mouseCallback);
	setTimerCallback(timerCallback);

	room1 = createScene("탈출","images/background.png");
	room2 = createScene("탈출", "images/background2.png");
	room3 = createScene("탈출", "images/background3.png");
	finish = createScene("탈출", "images/finish.png");

	l1 = createScene(" ", "images/l1.png");
	l2 = createScene(" ", "images/l2.png");
	l3 = createScene(" ", "images/l3.png");
	l4 = createScene(" ", "images/l4.png");
	l5 = createScene(" ", "images/l5.png");
	l6 = createScene(" ", "images/l6.png");

	h1 = createScene(" ", "images/h1.png");
	h2 = createScene(" ", "images/h2.png");
	h3 = createScene(" ", "images/h3.png");
	h4 = createScene(" ", "images/h4.png");
	h5 = createScene(" ", "images/h5.png");
	h6 = createScene(" ", "images/h6.png");

	r1 = createScene(" ", "images/r1.png");
	r2 = createScene(" ", "images/r2.png");
	r3 = createScene(" ", "images/r3.png");
	r4 = createScene(" ", "images/r4.png");
	r5 = createScene(" ", "images/r5.png");
	r6 = createScene(" ", "images/r6.png");
	r7 = createScene(" ", "images/r7.png");
	r8 = createScene(" ", "images/r8.png");
	r9 = createScene(" ", "images/r9.png");


	button = createObject("images/button.png", room1, 590, 70, false);
	scaleObject(button, 0.7f);
	start = createObject("images/start.png", room1, 590, 70, true);
	restart = createObject("images/restart.png", room1, 590, 70, false);
	tree = createObject("images/tree.png", room1, 392, 362, false);
	dog = createObject("images/dog.png", room1, dogX, 362, true);
	

	high = createObject("images/high.png", room2, 100, 600, false);
	low = createObject("images/low.png", room2, 100, 450, false);
	string = createObject("images/string.png", room2, 80, 280, true);
	gage = createObject("images/gage.png", room2, 25, 400, false);
	amount = createObject("images/amount.png", room2, 40, 420, false);
	human = createObject("images/human.png", room2, 150, 350, true);
	stringhuman = createObject("images/stringhuman.png", room2, 150, 350, false);

	leaf1 = createObject("images/leaf1.png", room3, 0, 0, true);
	leaf2 = createObject("images/leaf2.png", room3, 830, 0, true);
	key = createObject("images/key.png", room3, 350, 550, false);
	door = createObject("images/door.png", room3, 445, 230, true);
	restart2 = createObject("images/restart.png", finish, 500, 110, false);

	timer1 = createTimer(2.0f);
	timer2 = createTimer(2.0f);
	timer3 = createTimer(0.01f);

	timer4 = createTimer(5.0f);

	timerl1 = createTimer(0.3f);
	timerl2 = createTimer(0.3f);
	timerl3 = createTimer(0.3f);
	timerl4 = createTimer(0.3f);
	timerl5 = createTimer(0.3f);
	timerl6 = createTimer(0.3f);

	timerh1 = createTimer(0.3f);
	timerh2 = createTimer(0.3f);
	timerh3 = createTimer(0.3f);
	timerh4 = createTimer(0.3f);
	timerh5 = createTimer(0.3f);
	timerh6 = createTimer(0.3f);

	timerr1 = createTimer(0.3f);
	timerr2 = createTimer(0.3f);
	timerr3 = createTimer(0.3f);
	timerr4 = createTimer(0.3f);
	timerr5 = createTimer(0.3f);
	timerr6 = createTimer(0.3f);
	timerr7 = createTimer(0.3f);
	timerr8 = createTimer(0.3f);
	timerr9 = createTimer(1.0f);

	startGame(room1);
	return 0;
}