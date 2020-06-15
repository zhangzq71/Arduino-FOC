---
layout: default
title: Interactive Example
parent: Using the Code 
permalink: /interactive_example
---

# Interactive sketch example

This code is intended to better understand the procedure of writing the program and to understand the usages of different parts of the code.

This is the code of the library example `motor_full_control_serial_examples/magnetic_sensor/full_control_serial.ino`. For more library examples go to [link](library_examples)

### Toggle different parts of the code 
<div style="width:100%;margin-bottom:0px">
<a href ="javascript:show('mag_s');" id="mag_s" class="btn btn-primary">Magnetic sensor</a>
<a href="javascript:show('mot_s');" id="mot_s" class="btn">BLDC Motor</a> 
<a href="javascript:show('foc_s');" id="foc_s" class="btn">FOC routine</a> 
<a href="javascript:show('mon_s');" id="mon_s" class="btn">Monitoring</a> 
<a href="javascript:show('com_s');" id="com_s" class="btn">Communication</a> 
<a href="javascript:show('conf_s');" id="conf_s" class="btn">Configuration</a> 
<div>
<div class="language-cpp highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="cp">#include &lt;SimpleFOC.h&gt;
</span><span class="mag_s">
<span class="c1">// magnetic sensor instance</span>
<span class="n">MagneticSensor</span> <span class="n">AS5x4x</span> <span class="o">=</span> <span class="n">MagneticSensor</span><span class="p">(</span><span class="mi">10</span><span class="p">,</span> <span class="mi">16384</span><span class="p">,</span> <span class="mh">0x3FFF</span><span class="p">);</span></span>
<span class="mot_s">
<span class="c1">// motor instance</span>
<span class="n">BLDCMotor</span> <span class="n">motor</span> <span class="o">=</span> <span class="n">BLDCMotor</span><span class="p">(</span><span class="mi">9</span><span class="p">,</span> <span class="mi">5</span><span class="p">,</span> <span class="mi">6</span><span class="p">,</span> <span class="mi">11</span><span class="p">,</span> <span class="mi">8</span><span class="p">);</span>
</span>
<span class="kt">void</span> <span class="nf">setup</span><span class="p">()</span> <span class="p">{</span>
<span class="mag_s">
  <span class="c1">// initialize magnetic sensor hardware</span>
  <span class="n">AS5x4x</span><span class="p">.</span><span class="n">init</span><span class="p">();</span></span>
  <span class="mot_s"><span class="c1">// link the motor to the sensor</span>
  <span class="n">motor</span><span class="p">.</span><span class="n">linkSensor</span><span class="p">(</span><span class="o">&amp;</span><span class="n mag_s">AS5x4x</span><span class="n enc_s">encoder</span><span class="p">);</span></span>
<span class="conf_s">
  <span class="c1">// choose FOC modulation</span>
  <span class="n">motor</span><span class="p">.</span><span class="n">foc_modulation</span> <span class="o">=</span> <span class="n">FOCModulationType</span><span class="o">::</span><span class="n">SpaceVectorPWM</span><span class="p">;</span>

  <span class="c1">// power supply voltage [V]</span>
  <span class="n">motor</span><span class="p">.</span><span class="n">voltage_power_supply</span> <span class="o">=</span> <span class="mi">12</span><span class="p">;</span>
</span><span class="conf_s">
  <span class="c1">// set control loop type to be used</span>
  <span class="n">motor</span><span class="p">.</span><span class="n">controller</span> <span class="o">=</span> <span class="n">ControlType</span><span class="o">::</span><span class="n">voltage</span><span class="p">;</span>

  <span class="c1">// controller configuration based on the control type </span>
  <span class="n">motor</span><span class="p">.</span><span class="n">PI_velocity</span><span class="p">.</span><span class="n">P</span> <span class="o">=</span> <span class="mf">0.2</span><span class="p">;</span>
  <span class="n">motor</span><span class="p">.</span><span class="n">PI_velocity</span><span class="p">.</span><span class="n">I</span> <span class="o">=</span> <span class="mi">20</span><span class="p">;</span>
  <span class="c1">// default voltage_power_supply</span>
  <span class="n">motor</span><span class="p">.</span><span class="n">PI_velocity</span><span class="p">.</span><span class="n">voltage_limit</span> <span class="o">=</span> <span class="mi">12</span><span class="p">;</span>

  <span class="c1">// velocity low pass filtering time constant</span>
  <span class="n">motor</span><span class="p">.</span><span class="n">LPF_velocity</span><span class="p">.</span><span class="n">Tf</span> <span class="o">=</span> <span class="mf">0.01</span><span class="p">;</span>

  <span class="c1">// angle loop controller</span>
  <span class="n">motor</span><span class="p">.</span><span class="n">P_angle</span><span class="p">.</span><span class="n">P</span> <span class="o">=</span> <span class="mi">20</span><span class="p">;</span>
  <span class="c1">// angle loop velocity limit</span>
  <span class="n">motor</span><span class="p">.</span><span class="n">P_angle</span><span class="p">.</span><span class="n">velocity_limit</span> <span class="o">=</span> <span class="mi">50</span><span class="p"></span>
</span><span class="com_s mon_s">
  <span class="c1">// use monitoring with serial for motor init</span>
  <span class="c1">// monitoring port</span>
  <span class="n">Serial</span><span class="p">.</span><span class="n">begin</span><span class="p">(</span><span class="mi">115200</span><span class="p">);</span>
  <span class="c1">// comment out if not needed</span>
  <span class="n">motor</span><span class="p">.</span><span class="n">useMonitoring</span><span class="p">(</span><span class="n">Serial</span><span class="p">);</span>
</span><span class="mot_s">
  <span class="c1">// initialize motor</span>
  <span class="n">motor</span><span class="p">.</span><span class="n">init</span><span class="p">();</span></span>
  <span class="foc_s"><span class="c1">// align encoder and start FOC</span>
  <span class="n">motor</span><span class="p">.</span><span class="n">initFOC</span><span class="p">();</span></span>
<span class="foc_s">
  <span class="c1 ">// set the initial target value</span>
  <span class="n">motor</span><span class="p">.</span><span class="n">target</span> <span class="o">=</span> <span class="mi">2</span><span class="p">;</span></span>

<span class="com_s">
  <span class="n">Serial</span><span class="p">.</span><span class="n">println</span><span class="p">(</span><span class="s">"Full control example: "</span><span class="p">);</span>
  <span class="n">Serial</span><span class="p">.</span><span class="n">println</span><span class="p">(</span><span class="s">"Run user commands to configure and the motor (find the full command list in docs.simplefoc.com) </span><span class="se">\n</span><span class="s"> "</span><span class="p">);</span>
  <span class="n">Serial</span><span class="p">.</span><span class="n">println</span><span class="p">(</span><span class="s">"Initial motion control loop is voltage loop."</span><span class="p">);</span>
  <span class="n">Serial</span><span class="p">.</span><span class="n">println</span><span class="p">(</span><span class="s">"Initial target voltage 2V."</span><span class="p">);</span></span>
  
  <span class="n">_delay</span><span class="p">(</span><span class="mi">1000</span><span class="p">);</span>
<span class="p">}</span>


<span class="kt">void</span> <span class="nf">loop</span><span class="p">()</span> <span class="p">{</span>
  <span class="foc_s"><span class="c1">// iterative setting FOC phase voltage</span>
  <span class="n">motor</span><span class="p">.</span><span class="n">loopFOC</span><span class="p">();</span></span>

  <span class="foc_s"><span class="c1">// iterative function setting the outer loop target</span>
  <span class="c1">// velocity, position or voltage</span>
  <span class="c1">// if target not set in parameter uses motor.target variable</span>
  <span class="n">motor</span><span class="p">.</span><span class="n">move</span><span class="p">();</span></span>

  <span class="c1 mon_s com_s_hide">// output motor state variables to the monitoring port (Serial)</span>
  <span class="mon_s com_s_hide"><span class="n">motor</span><span class="p">.</span><span class="n">monitor</span><span class="p">();</span></span> 
  
  <span class="com_s"><span class="c1">// user communication</span>
  <span class="n">serialReceiveUserCommand</span><span class="p">();</span></span>
<span class="p">}</span>
<span class="com_s">
<span class="c1">// utility function enabling serial communication function with the user</span>
<span class="c1">// user can set the target values and set/get the motor configuration using motor commands </span>
<span class="c1">// see documentation for full command list </span>
<span class="c1">// </span>
<span class="c1">// this function can be implemented in serialEvent function as well</span>
<span class="kt">void</span> <span class="nf">serialReceiveUserCommand</span><span class="p">()</span> <span class="p">{</span>
  
  <span class="c1">// a string to hold incoming data</span>
  <span class="k">static</span> <span class="n">String</span> <span class="n">received_chars</span><span class="p">;</span>
  
  <span class="k">while</span> <span class="p">(</span><span class="n">Serial</span><span class="p">.</span><span class="n">available</span><span class="p">())</span> <span class="p">{</span>
    <span class="c1">// get the new byte:</span>
    <span class="kt">char</span> <span class="n">inChar</span> <span class="o">=</span> <span class="p">(</span><span class="kt">char</span><span class="p">)</span><span class="n">Serial</span><span class="p">.</span><span class="n">read</span><span class="p">();</span>
    <span class="c1">// add it to the string buffer:</span>
    <span class="n">received_chars</span> <span class="o">+=</span> <span class="n">inChar</span><span class="p">;</span>

    <span class="c1">// end of user input</span>
    <span class="k">if</span> <span class="p">(</span><span class="n">inChar</span> <span class="o">==</span> <span class="sc">'\n'</span><span class="p">)</span> <span class="p">{</span>
      
      <span class="c1">// execute the user command</span>
      <span class="n">motor</span><span class="p">.</span><span class="n">command</span><span class="p">(</span><span class="n">received_chars</span><span class="p">);</span>

      <span class="c1">// reset the command buffer </span>
      <span class="n">received_chars</span> <span class="o">=</span> <span class="s">""</span><span class="p">;</span>
    <span class="p">}</span>
  <span class="p">}</span>
<span class="p">}</span>
</span>

</code></pre></div></div>


<script type="text/javascript">
    var elems = document.getElementsByClassName('com_s');
    for (i = 0; i < elems.length; i++) {
        elems[i].style.display = "none";
    }
    var elems = document.getElementsByClassName('mon_s');
    for (i = 0; i < elems.length; i++) {
        elems[i].style.display = "none";
    }
    var elems = document.getElementsByClassName('conf_s');
    for (i = 0; i < elems.length; i++) {
        elems[i].style.display = "none";
    }
    var elems = document.getElementsByClassName('foc_s');
    for (i = 0; i < elems.length; i++) {
        elems[i].style.display = "none";
    }
    var elems = document.getElementsByClassName('mot_s');
    for (i = 0; i < elems.length; i++) {
        elems[i].style.display = "none";
    }
    var elems = document.getElementsByClassName('enc_s');
    for (i = 0; i < elems.length; i++) {
        elems[i].style.display = "none";
    }

    function show(str){
        var hide = document.getElementById(str).classList.contains("btn-primary");

        if(hide){
            document.getElementById(str).classList.remove("btn-primary");
            var elems = document.getElementsByClassName(str);
            for (i = 0; i < elems.length; i++) {
                elems[i].style.display = "none";
            }  
        }else{
            document.getElementById(str).classList.add("btn-primary");
            var elems = document.getElementsByClassName(str);
            for (i = 0; i < elems.length; i++) {
                elems[i].style.display = "inline";
            } 
            var elems = document.getElementsByClassName(str+"_hide");
            for (i = 0; i < elems.length; i++) {
                elems[i].style.display = "none";
            } 
        }
        return 0;
    }
</script>

