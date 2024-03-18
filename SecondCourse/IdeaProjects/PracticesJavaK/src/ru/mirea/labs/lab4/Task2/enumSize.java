package ru.mirea.labs.lab4.Task2;

public enum enumSize {
    L(40),
    M(38),
    S(36),
    XS(34),
    XXS(32) {
        @Override
        public String getDescription() {
           return("Child size");
        }
    };

    private int euroSize;

    enumSize(int euroSize) {
        this.euroSize = euroSize;
    }

    public String getDescription() {
        return("Adult size");
    }
}
