package packaaage;
public  abstract class Vehicle {
    public abstract int getMode();
}
class Bus extends Vehicle{
    public int getMode(){
        return 2;
    }
}
class NEWW{
    public static void main(String[] args) {
        
        Bus newbus = new Bus();
        newbus.getMode();
    }
}