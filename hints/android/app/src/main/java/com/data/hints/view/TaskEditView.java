package com.data.hints.view;

import android.content.Context;
import android.util.AttributeSet;
import android.widget.FrameLayout;
import android.widget.NumberPicker;
import android.widget.TimePicker;

import com.data.hints.R;
import com.data.hints.core.Task;

public class TaskEditView extends FrameLayout {

    private final NumberPicker dayOfMonth_;
    private final TimePicker timeOfDay_;

    public TaskEditView(Context context) {
        this(context, null, 0);
    }

    public TaskEditView(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public TaskEditView(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);

        inflate(context, R.layout.view_task_edit, this);

        dayOfMonth_ = (NumberPicker) findViewById(R.id.task_trigger_day_of_month);
        dayOfMonth_.setMinValue(1);
        dayOfMonth_.setMaxValue(28);

        timeOfDay_ = (TimePicker) findViewById(R.id.task_trigger_time_of_day);
        timeOfDay_.setIs24HourView(true);
    }

    public void setTask(Task task) {
        dayOfMonth_.setValue(task.getTriggerTime().dayOfMonth);
        timeOfDay_.setCurrentHour(task.getTriggerTime().timeOfDay.hour);
        timeOfDay_.setCurrentMinute(task.getTriggerTime().timeOfDay.minute);
    }
}
