// server.js
const express = require("express");
const fs = require("fs");
const app = express();

app.use(express.json());
app.use(express.static("../ui")); // your HTML folder

// RECEIVE STUDENT FEEDBACK
app.post("/submit-feedback", (req, res) => {
    const data = JSON.parse(fs.readFileSync("data.json"));
    data.feedback.push(req.body);
    fs.writeFileSync("data.json", JSON.stringify(data, null, 2));
    res.json({ success: true });
});

// SEND DATA TO ADMIN
app.get("/admin-data", (req, res) => {
    const data = JSON.parse(fs.readFileSync("data.json"));
    res.json(data.feedback);
});

app.listen(3000, () => {
    console.log("Server running on http://localhost:3000");
});