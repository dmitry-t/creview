package com.data.hints.core;

public class TimeOfDay {
    public final int hour;
    public final int minute;

    public TimeOfDay(int hour, int minute) {
        this.hour = hour;
        this.minute = minute;

        if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
            throw new IllegalArgumentException("Bad time of day: " + this);
        }
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        TimeOfDay timeOfDay = (TimeOfDay) o;

        if (hour != timeOfDay.hour) return false;
        if (minute != timeOfDay.minute) return false;

        return true;
    }

    @Override
    public int hashCode() {
        int result = hour;
        result = 31 * result + minute;
        return result;
    }

    @Override
    public String toString() {
        return String.format("{%d:%2d}", hour, minute);
    }
}
