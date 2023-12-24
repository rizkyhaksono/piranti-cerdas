import { LineChart, PieChart, AreaChart } from "react-chartkick";
import "chartkick/chart.js";

export default function ChartComponent({ data }) {
  console.log(`Data ${data}`);

  if (!data || !Array.isArray(data) || data.length === 0) {
    return <p>No data available for charts</p>;
  }

  const chartData = data[0];

  const lineChartData = [{ [chartData.created_at]: chartData.data }];

  const pieChartData = [[chartData.created_at, chartData.data]];

  const areaChartData = [{ [chartData.created_at]: chartData.data }];

  return (
    <>
      <div className="container mx-auto mt-10">
        <LineChart data={lineChartData.reduce((acc, obj) => ({ ...acc, ...obj }), {})} />
        <PieChart data={pieChartData} />
        <AreaChart data={areaChartData.reduce((acc, obj) => ({ ...acc, ...obj }), {})} />
      </div>
    </>
  );
}
