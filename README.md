# TinkerCAD Arduino Projects

This repository contains my solutions for advanced circuit challenges and a final custom project.

### 1. Fundamental Skills Learned
From the initial three challenges, I mastered core Arduino programming functions:
* **Non-blocking Timing:** Using `millis()` to run multiple tasks simultaneously without pausing the code.
* **Analog Control:** Using `analogRead` (Potentiometer) and `analogWrite` (RGB LED) to control intensity and color.
* **User Input:** Using `INPUT_PULLUP` for stable button sensing and calculating reaction times.

### 2. Custom Project: Digital Mood Thermometer
For the final project, I researched an idea online to build a **Digital Mood Thermometer**.

**Project Brief:**
This project uses a **TMP36 Temperature Sensor** to monitor environmental heat. Instead of just reading numbers, it uses an **RGB LED** to provide instant visual feedback:
* **Blue:** Cold environment.
* **Green:** Comfortable temperature.
* **Red:** Hot/Warning state.

It combines temperature sensing with color-coded logic to create a simple, intuitive monitoring device.
