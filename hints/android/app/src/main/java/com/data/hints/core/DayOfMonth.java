package com.data.hints.core;

public class DayOfMonth {
    public final int day;

    public DayOfMonth(int day) {
        this.day = day;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        DayOfMonth that = (DayOfMonth) o;

        return day == that.day;
    }

    @Override
    public int hashCode() {
        return day;
    }

    @Override
    public String toString() {
        return String.format("DayOfMonth{%d}", day);
    }
}
