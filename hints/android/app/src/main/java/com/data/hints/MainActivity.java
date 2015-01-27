package com.data.hints;

import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

import com.data.hints.app.NotificationService;
import com.data.hints.core.Task;
import com.data.hints.schedule.Scheduler;

import java.util.GregorianCalendar;


public class MainActivity extends ActionBarActivity {

    private NotificationService notificationService_;
    private Scheduler scheduler_;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        notificationService_ = new NotificationService(MainActivity.this);
        scheduler_ = new Scheduler(notificationService_);

        findViewById(R.id.activity_main_notify_button).setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {
                final GregorianCalendar calendar = new GregorianCalendar();
                calendar.add(GregorianCalendar.SECOND, 5);
                scheduler_.schedule(new Task("Title", "Text"), calendar.getTime());
            }
        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

}
