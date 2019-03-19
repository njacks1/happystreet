#include "library.h"

void line_and_turn(int radius, double const pi, double r, double g, double b){
	set_pen_color(r, g, b);
	double circumference = 2*pi*radius;
	double dist_per_degree = circumference / 360;
	int counter = 360;
	set_heading_degrees(90);
	start_shape();
	while (counter>0){
		note_position();
		draw_distance(dist_per_degree);
		turn_right_by_degrees(1);
		counter = counter - 1;
	}
	fill_shape();
}


void moon(double const pi, double r, double g, double b){
	int moon_radius = 40;
	line_and_turn(moon_radius, pi, r, g, b);
}

void night(double const pi){
	set_pen_color(0.1, 0.1, 0.1);
	fill_rectangle(0, 0, 1000, 800);
	move_to(random_in_range(200,800), random_in_range(100,200));
	double r = 1.0;
	double g = 1.0;
	double b = 1.0;
	moon(pi,r,g,b);
}

void sun(double const pi, double r, double g, double b){
	int sun_radius = 75;      //radius for sun
	line_and_turn(sun_radius, pi, r, g, b);
}

void afternoon(double const pi){
	set_pen_color(0.10, 0.40, 1.00);
	fill_rectangle(0, 0, 1000, 800);
	move_to(random_in_range(100, 300), random_in_range(100, 200));
	double r = 0.8;
	double g = 0.8;
	double b = 0.0;
	sun(pi,r,g,b);
}

void morning(double const pi){
	set_pen_color(0.30, 0.50, 0.80);
	fill_rectangle(0, 0, 1000, 800);       //!!! Needs RGB Values
	move_to(random_in_range(600, 800), random_in_range(100, 150));
	double r = 1.0;
	double g = 1.0;
	double b = 0.0;
	sun(pi,r,g,b);
}

void decide_moon_sun(int time, double const pi){
	if (time>=0 && time<=6 || time>=21 && time<24){
		night(pi);
	}
	else if (time >= 7 && time <= 14){
		morning(pi);
	}
	else afternoon(pi);
}

void mountains(){
	set_pen_color(color::dark_grey);
	move_to(0, 480);
	int nn = 4;
	start_shape();
	while (nn>0){
		note_position();
		set_heading_degrees(90);
		turn_right_by_degrees(-random_in_range(30, 35));
		draw_distance(random_in_range(200, 300));
		note_position();
		set_heading_degrees(90);
		turn_right_by_degrees(random_in_range(30, 35));
		draw_distance(random_in_range(250, 350));
		nn = nn - 1;
	}
	note_position();
	draw_to(1000, 800);
	note_position();
	draw_to(0, 800);
	note_position();
	draw_to(0, 480);
	note_position();
	fill_shape();
	move_to(0, 550);
}

void mountains2(){
	set_pen_color(color::grey);
	move_to(0, 500);
	int m = 6;
	start_shape();
	while (m > 0){
		note_position();
		set_heading_degrees(90);
		turn_right_by_degrees(-random_in_range(30, 35));
		draw_distance(random_in_range(100, 150));
		note_position();
		set_heading_degrees(90);
		turn_right_by_degrees(random_in_range(30, 35));
		draw_distance(random_in_range(125, 150));
		m = m - 1;
	}
	note_position();
	draw_to(1000, 800);
	note_position();
	draw_to(0, 800);
	note_position();
	draw_to(0, 500);
	note_position();
	fill_shape();
}

void log(int xxxxx){
	int xxxx = random_in_range(15,25);
	int yyyy = random_in_range(100, 150);
	set_heading_degrees(0);
	set_pen_color(color::brown);
	start_shape();
	note_position();
	draw_distance(yyyy);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(xxxx);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(yyyy);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(xxxx);
	note_position();
	fill_shape();
	move_to(xxxxx + (xxxx / 2), 720+yyyy);
	set_pen_width(3);
	set_pen_color(color::green);
	int kk = 1000;
	while (kk > 0){
		move_to(xxxxx - 30 + random_in_range(0, 60), 525 + yyyy - random_in_range(0, 100));
		draw_point();
		kk = kk - 1;
	}
}

void tree(){
	int xxxxx = random_in_range(890, 970);
	move_to(xxxxx, 740);
	log(xxxxx);
}

void grass(){
	fill_rectangle(0, 700, 1000, 780, color::dark_green);
}

void street(){
	fill_rectangle(0, 780, 1000, 800, color::grey);
}

void main(){
	double const pi = acos(-1.0);
	make_window(1000, 800);
	cout << "What time of the day is it? (Using 24-hour clock integers)" << endl;
	int time;
	cin >> time;
	decide_moon_sun(time, pi);  //sky color
	mountains();
	mountains2();
	grass();
	street();
	tree();
	//background();
}
