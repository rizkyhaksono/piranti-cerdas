import axios from "axios";

export default async function sensorApi() {
  try {
    const response = await axios.get("http://localhost:3000/api/sensor");
    const data = response.data;
    return { status: 200, data };
  } catch (error) {
    console.error("Error:", error);
    return { status: 500, error: "Internal Server Error" };
  }
}
