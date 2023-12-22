"use client";

import Link from "next/link";
import ChartComponent from "../../components/ChartComponent";

export default function Home() {
  return (
    <>
      <div className="text-stone-700 font-sans">
        <Link href={"documentation"}>
          <p className="font-normal text-base">API Documentation</p>
        </Link>
        <div className="font-medium text-2xl">Dashboard Smart Home</div>

        <ChartComponent />
      </div>
    </>
  );
}
