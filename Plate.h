class Plate {
    private:
        int length;
        int width;
        int price;
    public:
        Plate();
        
        Plate(int length, int width, int price);

        double getProfit();

        //void printPlate();
};
