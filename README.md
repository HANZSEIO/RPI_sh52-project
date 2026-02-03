<h1 align="center"> ESP8266 MQTT Smart Relay</h1>

<p align="center">
  <b>IoT Smart Home Project using ESP8266, MQTT, and PlatformIO</b><br>
  <i>Simple, modular, and scalable relay control system</i>
</p>

<hr>

<h2>📌 Project Overview</h2>
<p>
Project ini merupakan sistem <b>Smart Home berbasis IoT</b> yang menggunakan
<b>ESP8266</b> sebagai node, <b>MQTT</b> sebagai protokol komunikasi,
dan <b>Mosquitto</b> sebagai broker.
</p>

<p>
Setiap relay dapat dikontrol secara real-time melalui MQTT topic,
dan status relay akan dipublish kembali ke broker.
</p>

<hr>

<h2> System Architecture</h2>

<pre>
[ MQTT Client ]
     |
     v
[ Mosquitto Broker ]
     |
     v
[ ESP8266 Node ]
     |
     v
[ Relay Module ]
</pre>

<hr>

<h2> Technology Stack</h2>

<ul>
  <li><b>Microcontroller:</b> ESP8266 (ESP-12E)</li>
  <li><b>Framework:</b> Arduino (via PlatformIO)</li>
  <li><b>Protocol:</b> MQTT</li>
  <li><b>Broker:</b> Mosquitto</li>
  <li><b>Testing Tool:</b> MQTTX / MQTT Explorer</li>
</ul>

<hr>

<h2> MQTT Topic Structure</h2>

<table border="1" cellpadding="6">
  <tr>
    <th>Topic</th>
    <th>Function</th>
  </tr>
  <tr>
    <td><code>smarthome/node1/relay/1/set</code></td>
    <td>Control Relay 1 (ON / OFF)</td>
  </tr>
  <tr>
    <td><code>smarthome/node1/relay/1/state</code></td>
    <td>Relay 1 status feedback</td>
  </tr>
  <tr>
    <td><code>smarthome/node1/status</code></td>
    <td>Node online/offline status</td>
  </tr>
</table>

<hr>

<h2> How to Run</h2>

<ol>
  <li>Install Mosquitto MQTT Broker</li>
  <li>Upload firmware using PlatformIO</li>
  <li>Pastikan ESP dan PC berada di jaringan yang sama</li>
  <li>Subscribe / Publish topic via MQTTX</li>
</ol>

<hr>

<h2>📁 Project Structure</h2>

<pre>
RPI/
├── src/
│   └── main.cpp
├── platformio.ini
├── lib/
├── include/
└── README.md
</pre>

<hr>

<h2> Future Development</h2>

<ul>
  <li>Web dashboard</li>
  <li>Home Assistant integration</li>
  <li>Authentication & TLS MQTT</li>
  <li>Multiple ESP nodes</li>
</ul>

<hr>

<h2>Author : HANZSEIO, sirghani, syaffiqsdd</h2>

<p>
<b>Hanz</b><br>
IoT & Embedded System Enthusiast
</p>

