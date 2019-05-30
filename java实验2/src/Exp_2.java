import java.util.Scanner;

interface Shape{
    double area(double givenValue,double secValue);
}
class Square implements Shape{

    @Override
    public double area(double givenValue,double secValue) {
        return givenValue * givenValue;
    }

}
class Circle implements Shape{

    @Override
    public double area(double givenValue,double s) {
        return Math.PI * givenValue * givenValue;
    }
}
class Triangle implements Shape{

    @Override
    public double area(double basement,double hight) {
        return basement * hight / 2.0;
    }
}
