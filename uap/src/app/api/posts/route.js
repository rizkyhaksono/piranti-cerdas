import { NextResponse } from "next/server";
import mysql from "mysql2/promise";

const dbConfig = {
  host: process.env.DB_HOST,
  user: process.env.DB_USER,
  password: process.env.DB_PASSWORD,
  database: process.env.DB_DATABASE,
  port: process.env.DB_PORT,
};

export async function GET() {
  try {
    const connection = await mysql.createConnection(dbConfig);
    const query = await connection.execute("SELECT * FROM `posts`");
    return NextResponse.json({ data: query[0] });
  } catch (error) {
    console.log("Error :", error);
  }
}

export async function POST(req, res) {
  try {
    const { title } = await req.json();

    const connection = await mysql.createConnection(dbConfig);
    await connection.execute("INSERT INTO `posts` (title) VALUES (?)", [title]);

    return NextResponse.json({ success: true, message: "Post added successfully" });
  } catch (error) {
    console.log("Error :", error);
    return NextResponse.error("Internal Server Error", 500);
  }
}
