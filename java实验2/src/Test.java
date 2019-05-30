public  class Test{
    public static void main(String[] args) {
        Shape square = new Square();
        Shape circle = new Circle();
        Shape triangle = new Triangle();

        System.out.println(square.area(2,1));
        System.out.println(circle.area(3,1));
        System.out.println(triangle.area(5,5));
    }
}
