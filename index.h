const char MAIN_page[] PROGMEM = R"=====( 
<!DOCTYPE html>
<html>
<head>
  <title>IoT Weather Station</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@300;500;700&display=swap" rel="stylesheet">
  <link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.0/css/all.min.css" rel="stylesheet">
  <style>
    * { margin: 0; padding: 0; box-sizing: border-box; }
    body {
      font-family: 'Poppins', sans-serif;
      background: linear-gradient(135deg, #667eea, #764ba2);
      color: #fff;
      display: flex;
      justify-content: center;
      align-items: center;
      height: 100vh;
    }
    .widget {
      background: rgba(255, 255, 255, 0.1);
      border-radius: 20px;
      box-shadow: 0 8px 32px rgba(0, 0, 0, 0.2);
      backdrop-filter: blur(10px);
      width: 90%;
      max-width: 500px;
      padding: 20px;
    }
    .header {
      text-align: center;
      margin-bottom: 20px;
    }
    .header h1 {
      font-size: 28px;
    }
    .data {
      display: flex;
      flex-wrap: wrap;
      justify-content: space-around;
    }
    .card {
      flex: 0 0 45%;
      background: rgba(255, 255, 255, 0.15);
      margin: 10px 0;
      padding: 20px;
      border-radius: 15px;
      text-align: center;
    }
    .card i {
      font-size: 30px;
      margin-bottom: 10px;
      color: #ffeb3b;
    }
    .card h2 {
      font-size: 18px;
      margin-bottom: 5px;
      font-weight: 500;
    }
    .card p {
      font-size: 22px;
      font-weight: bold;
    }
    .footer {
      text-align: center;
      margin-top: 20px;
      font-size: 14px;
      opacity: 0.8;
    }
  </style>
</head>
<body>
  <div class="widget">
    <div class="header">
      <h1>Weather Station</h1>
      <div id="date">Loading...</div>
    </div>
    <div class="data">
      <div class="card">
        <i class="fas fa-sun"></i>
        <h2>Temperature</h2>
        <p id="temp">-- &deg;C</p>
      </div>
      <div class="card">
        <i class="fas fa-tint"></i>
        <h2>Humidity</h2>
        <p id="humidity">--%</p>
      </div>
      <div class="card">
        <i class="fas fa-cloud-showers-heavy"></i>
        <h2>Rain</h2>
        <p id="rain">--%</p>
      </div>
      <div class="card">
        <i class="fas fa-tachometer-alt"></i>
        <h2>Pressure</h2>
        <p id="pressure">-- mb</p>
      </div>
    </div>
    <div class="footer">
      Alerts enabled: Heat (>40°C) & Rain (>30%)
    </div>
  </div>

  <script>
    let tempAlertShown = false;
    let rainAlertShown = false;

    setInterval(drawClock, 2000);

    function drawClock() {
      var now = new Date();
      document.getElementById("date").innerHTML = now.toDateString();

      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState === 4 && this.status === 200) {
          try {
            var obj = JSON.parse(this.responseText);
            let temp = Math.round(obj.Temperature || 0);
            let rain = parseInt(obj.Rain || 0);
            let humidity = Math.round(obj.Humidity || 0);
            let pressure = obj.Pressuremb > 0 ? Math.round(obj.Pressuremb) + " mb" : "N/A";

            document.getElementById("rain").innerHTML = rain + "%";
            document.getElementById("temp").innerHTML = temp + "&deg;C";
            document.getElementById("humidity").innerHTML = humidity + "%";
            document.getElementById("pressure").innerHTML = pressure;

            // ALERTS
            if (temp > 40 && !tempAlertShown) {
              alert("⚠ High Temperature Alert: " + temp + "°C");
              tempAlertShown = true;
            }
            if (temp <= 40) tempAlertShown = false;

            if (rain > 30 && !rainAlertShown) {
              alert("☔ Rain Alert: " + rain + "%");
              rainAlertShown = true;
            }
            if (rain <= 30) rainAlertShown = false;

          } catch (e) {
            console.error("Error parsing sensor data:", e);
          }
        }
      };
      xhttp.open("GET", "readADC", true);
      xhttp.send();
    }
  </script>
</body>
</html>
)=====";
