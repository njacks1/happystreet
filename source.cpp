void line_and_turn(int const radius, double const pi, int const color_of_circle){
  int circumference = 2*pi*radius;
  int dist_per_degree = circumference/360;
  int counter  = 360;
  set_heading_degrees(90);
  start_shape();
  while (counter>360){
    note_poisition();
    draw_distance(dist_per_degree)
    turn_right_by_degrees(1);
    counter=counter-1;
  }
  fill_shape(color_of_circle);
}

void sun(double const pi){
  int const sun_radius = 75;      //radius for sun
  int const color_of_circle = 6;
  line_and_turn(sun_radius, pi, color_of_circle);
}

void moon(double const pi){
  int const moon_radius = 50;
  int const color_of_circle = 6;
  line_and_turn(moon_radius, pi, color_of_circle);
}

void mountains(){
  move_to(0, 480);
  int nn = 3;
  start_shape();
  while(nn>0){
    note_position();
    set_heading_degrees(90);
    turn_right_by_degrees(random_in_range(55-65));
    draw_distance(random_in_range(125-175));
    note_position();
    set_heading_degrees(90);
    turn_right_by_degrees(-random_in_range(55-65));
    draw_distance(random_in_range(125-175));
    nn = nn-1;
  }
  note_poisiton()
  draw_to(0,480);
  note_position();
  fill_shape();
  
}

void main(){
  double const pi = acos(-1.0);
  sun(pi);
}
