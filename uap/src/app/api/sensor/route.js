import mysql from "mysql2/promise";
import { createPool } from "mysql2/promise";
import { NextResponse } from "next/server";

const dbConfig = {
  host: process.env.DB_HOST,
  user: process.env.DB_USER,
  password: process.env.DB_PASSWORD,
  database: process.env.DB_DATABASE,
  port: process.env.DB_PORT,
};

const pool = createPool(dbConfig);

export async function GET() {
  try {
    const connection = await pool.getConnection();
    const query = await connection.execute("SELECT * FROM `sensor` ORDER BY created_at DESC LIMIT 20");
    connection.release();
    return NextResponse.json({ data: query[0] });
  } catch (error) {
    console.error("Error in GET route:", error);
    return NextResponse.error("Internal Server Error", 500);
  }
}

export async function POST(req, res) {
  try {
    const { jarak, ldr_value } = await req.json();

    const connection = await pool.getConnection();
    await connection.execute("INSERT INTO `sensor` (jarak, ldr_value) VALUES (?, ?)", [jarak, ldr_value]);
    connection.release();

    return NextResponse.json({ success: true, message: "Post added successfully" });
  } catch (error) {
    console.log("Error :", error);
    return NextResponse.error("Internal Server Error", 500);
  }
}
