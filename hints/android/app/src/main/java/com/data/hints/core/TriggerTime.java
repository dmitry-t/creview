package com.data.hints.core;

public class TriggerTime {
    public final Short dayOfMonth;
    public final TimeOfDay timeOfDay;

    public static final TriggerTime UNDEFINED = new TriggerTime(null, null);

    public TriggerTime(Short dayOfMonth, TimeOfDay timeOfDay) {
        this.dayOfMonth = dayOfMonth;
        this.timeOfDay = timeOfDay;
    }

    @Override
    public String toString() {
        return String.format("TriggerTime{dayOfMonth=%s, timeOfDay=%s}", dayOfMonth, timeOfDay);
    }
}
