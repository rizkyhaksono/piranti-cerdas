import { LineChart, PieChart, AreaChart } from "react-chartkick";
import "chartkick/chart.js";

export default function ChartComponent({ data }) {
  if (!data || !Array.isArray(data) || data.length === 0) {
    return <p className="flex flex-row justify-center">Loading...</p>;
  }

  const lineChartData = data.map((entry) => ({ [entry.created_at]: entry.jarak }));
  const pieChartData = data.map((entry) => [entry.ldr_value, entry.jarak]);
  const areaChartData = data.map((entry) => ({ [entry.created_at]: entry.jarak }));

  return (
    <>
      <div className="container mx-auto mt-10">
        <h2>Line Chart</h2>
        <LineChart data={lineChartData.reduce((acc, obj) => ({ ...acc, ...obj }), {})} />

        <h2>Pie Chart</h2>
        <PieChart data={pieChartData} />

        <h2>Area Chart</h2>
        <AreaChart data={areaChartData.reduce((acc, obj) => ({ ...acc, ...obj }), {})} />
      </div>
    </>
  );
}
