import java.util.*;
class Area_calculaor{
		public double calculate_area(int r){
			return Math.PI*r*r;
		}
		
		public int calculate_area(int length, int breadth){
			return length*breadth;
		}

		public double calculate_area(int a,int b, int c){
			double s = (a+b+c)/2;
			return Math.sqrt(s*(s-a)*(s-b)*(s-c));
		}

		
}

class shapes{
	public static void main(String[] args){

		Area_calculaor my_calculator = new Area_calculaor();
		System.out.print("The area of rectangle 10 20 is : ");
		System.out.print(my_calculator.calculate_area(10,20) + " \n");

		System.out.print("The area of Circle radius(5) is : ");
		System.out.print(my_calculator.calculate_area(5) + " \n");

		System.out.print("The area of triangle 3 4 5 is : ");
		System.out.print(my_calculator.calculate_area(3,4,5) + " \n");

	}


}

