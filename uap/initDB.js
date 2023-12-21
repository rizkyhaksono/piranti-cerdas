// initDB.js
// const pool = require('./db');
import pool from "./db";

async function initDB() {
  try {
    const connection = await pool.getConnection();
    await connection.query(`
      CREATE TABLE IF NOT EXISTS items (
        id INT AUTO_INCREMENT PRIMARY KEY,
        name VARCHAR(255) NOT NULL
      )
    `);
    await connection.query(`
      CREATE TABLE IF NOT EXISTS categories (
        id INT AUTO_INCREMENT PRIMARY KEY,
        name VARCHAR(255) NOT NULL
      )
    `);
    connection.release();
    console.log("Database tables initialized");
  } catch (error) {
    console.error("Error initializing database tables:", error);
  }
}

initDB();
