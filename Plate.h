class Plate {
    private:
        int length;
        int width;
        int price;
    public:
        Plate();
        
        Plate(int length, int width, int price);

        int getPrice();

        int getWidth();

        int getLength();

        bool samePlate(int length, int width);

        //void printPlate();
};
