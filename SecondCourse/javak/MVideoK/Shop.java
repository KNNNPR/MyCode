package ru.mirea.lab2.MVideoK;

import java.util.ArrayList;

public class Shop {
    private ArrayList<Computer> assort;
    public Shop(){
        assort = new ArrayList<Computer>();
    }
    public Computer searchComp(String newBrand, String newModel){
        for(int i = 0; i < assort.size(); i++){
            if (assort.get(i).getBrand().equals(newBrand) && assort.get(i).getModel().equals(newModel)){
                System.out.println(assort.get(i).toString());
                return (assort.get(i));
            }
        }
        System.out.println("Computer not found");
        return(null);
    }
    public void addComputer(String newBrand, String newModel){
        Computer newComp = new Computer(newBrand, newModel);
        System.out.println("Computer Added");
        assort.add(newComp);
    }
    public void removeComputer(String newBrand, String newModel){
        if (searchComp(newBrand, newModel) != null) {
            assort.remove(searchComp(newBrand, newModel));
            System.out.println("Computer removed");
        }
        else {
            System.out.println("Error");
        }
    }
}
