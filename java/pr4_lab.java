class Shape{
    void numberOfSides(){}
}
class rectangle extends Shape{
    void numberOfSides(){
        System.out.println("A rectangle has 4 sides");
    }
}
class traingle extends Shape{
    void numberOfSides(){
        System.out.println("a traingle has 3 sides");
    }
}
class hexagon extends Shape{
    void numberOfSides(){
        System.out.println("Hexagon has 6 sides");
    }
}

class pr4_lab{
    public static void main(String[] args){
        traingle my_traingle = new traingle();
        hexagon my_Hexagon = new hexagon();
        rectangle my_Rectangle = new rectangle();
        my_traingle.numberOfSides();
        my_Hexagon.numberOfSides();
        my_Rectangle.numberOfSides();
    }
}
