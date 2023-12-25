"use client";

import Link from "next/link";
import ChartComponent from "./components/ChartComponent";
import sensorApi from "./utils/sensorApi";
import { useEffect, useState } from "react";
import NavbarComponent from "./components/NavbarComponent";

export default function Home() {
  const [sensorData, setSensorData] = useState(null);

  useEffect(() => {
    const fetchData = async () => {
      try {
        const response = await sensorApi();
        console.log("API Response:", response);
        setSensorData(response.data.data);
      } catch (error) {
        console.error("Error:", error);
      }
    };

    fetchData();
  }, []);

  return (
    <>
      <NavbarComponent />
      <div className="text-stone-700 font-sans">
        <div className="container mx-auto text-center mt-10 font-bold text-3xl">Dashboard Smart Home</div>

        <ChartComponent data={sensorData} />
      </div>
    </>
  );
}
