<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Multi-Timezone Clocks</title>
    <style>
        body {
            display: flex;
            justify-content: center;
            align-items: center;
            flex-wrap: wrap;
            height: 100vh;
            background-color: #f4f4f4;
        }
        .clock-container {
            text-align: center;
            margin: 20px;
        }
        .clock {
            width: 100px;
            height: 100px;
            border: 5px solid black;
            border-radius: 50%;
            position: relative;
        }
        .hand {
            width: 50%;
            height: 2px;
            background: black;
            position: absolute;
            top: 50%;
            transform-origin: 100%;
            transform: rotate(90deg);
            transition: transform 0.5s cubic-bezier(0.4, 2.3, 0.3, 1);
        }
        .minute {
            height: 3px;
            background: gray;
        }
        .second {
            height: 1px;
            background: red;
        }
        .timezone {
            font-weight: bold;
            margin-top: 10px;
        }
    </style>
</head>
<body>

    <div class="clock-container">
        <div class="clock" id="ph-clock">
            <div class="hand hour"></div>
            <div class="hand minute"></div>
            <div class="hand second"></div>
        </div>
        <div class="timezone">Philippines Time (PHT)</div>
    </div>

    <div class="clock-container">
        <div class="clock" id="pst-clock">
            <div class="hand hour"></div>
            <div class="hand minute"></div>
            <div class="hand second"></div>
        </div>
        <div class="timezone">Pacific Time (PST)</div>
    </div>

    <div class="clock-container">
        <div class="clock" id="est-clock">
            <div class="hand hour"></div>
            <div class="hand minute"></div>
            <div class="hand second"></div>
        </div>
        <div class="timezone">Eastern Time (EST)</div>
    </div>

    <div class="clock-container">
        <div class="clock" id="cst-clock">
            <div class="hand hour"></div>
            <div class="hand minute"></div>
            <div class="hand second"></div>
        </div>
        <div class="timezone">Central Time (CST)</div>
    </div>

    <script>
        function updateClock(clockId, offset) {
            const now = new Date();
            const utc = now.getTime() + now.getTimezoneOffset() * 60000;
            const localTime = new Date(utc + (3600000 * offset));

            const hours = localTime.getHours() % 12;
            const minutes = localTime.getMinutes();
            const seconds = localTime.getSeconds();

            const hourDeg = (hours * 30) + (minutes / 2);
            const minuteDeg = (minutes * 6);
            const secondDeg = (seconds * 6);

            const clock = document.getElementById(clockId);
            clock.querySelector('.hour').style.transform = `rotate(${hourDeg}deg)`;
            clock.querySelector('.minute').style.transform = `rotate(${minuteDeg}deg)`;
            clock.querySelector('.second').style.transform = `rotate(${secondDeg}deg)`;
        }

        function updateClocks() {
            updateClock('ph-clock', 8); // PHT (UTC+8)
            updateClock('pst-clock', -8); // PST (UTC-8)
            updateClock('est-clock', -5); // EST (UTC-5)
            updateClock('cst-clock', -6); // CST (UTC-6)
        }

        setInterval(updateClocks, 1000);
        updateClocks();
    </script>

</body>
</html>
