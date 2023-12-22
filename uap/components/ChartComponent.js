import { LineChart, PieChart, AreaChart } from "react-chartkick";
import "chartkick/chart.js";

export default function ChartComponent() {
  return (
    <>
      <LineChart data={{ "2023-05-13": 2, "2023-05-14": 5 }} />
      <PieChart
        data={[
          ["Blueberry", 44],
          ["Strawberry", 23],
        ]}
      />
      <AreaChart data={{ "2021-01-01 00:00:00 -0800": 2, "2021-01-01 00:01:00 -0800": 5 }} />
    </>
  );
}
