import React, { useState, useEffect } from 'react';
import { Bar } from 'react-chartjs-2';
import './App.css';

function App() {
  const [partySupport, setPartySupport] = useState([]);
  const [totalVotes, setTotalVotes] = useState(0);
  const [voted, setVoted] = useState(false);
  const [feedback, setFeedback] = useState('');
  const [feedbackList, setFeedbackList] = useState([]);

  // APIからデータを取得する関数
  const fetchSupportData = async () => {
    try {
      const response = await fetch('https://jsonplaceholder.typicode.com/posts'); // ここでデモAPIを指定
      const data = await response.json();
      
      // 仮のデータを設定（APIのデータに応じて調整）
      const initialSupport = data.slice(0, 4).map((item, index) => ({
        party: `Party ${String.fromCharCode(65 + index)}`, // A, B, C, D
        support: Math.floor(Math.random() * 100), // ランダムな支持率
        details: item.body // ここではAPIのボディを詳細情報として使用
      }));
      setPartySupport(initialSupport);
    } catch (error) {
      console.error("データ取得エラー:", error);
    }
  };

  useEffect(() => {
    fetchSupportData(); // コンポーネントがマウントされたときにデータを取得
  }, []);

  const handleVote = (partyIndex) => {
    const updatedSupport = partySupport.map((party, index) => {
      if (index === partyIndex) {
        return { ...party, support: party.support + 1 };
      }
      return { ...party, support: Math.floor(party.support * (totalVotes / (totalVotes + 1))) }; // 他の党の支持率を調整
    });

    setPartySupport(updatedSupport);
    setTotalVotes(totalVotes + 1); // 投票数をカウント
    setVoted(true); // 投票したことを記録
  };

  const handleReset = () => {
    setPartySupport([]);
    setTotalVotes(0);
    setVoted(false);
  };

  const handleFeedbackChange = (event) => {
    setFeedback(event.target.value);
  };

  const submitFeedback = () => {
    if (feedback) {
      setFeedbackList([...feedbackList, feedback]);
      setFeedback('');
    }
  };

  const calculateSupportPercentages = () => {
    return partySupport.map(party => {
      return {
        party: party.party,
        support: party.support,
        percentage: totalVotes > 0 ? Math.round((party.support / totalVotes) * 100) : 0
      };
    });
  };

  const chartData = {
    labels: calculateSupportPercentages().map(party => party.party),
    datasets: [
      {
        label: '支持率 (%)',
        data: calculateSupportPercentages().map(party => party.percentage),
        backgroundColor: [
          'rgba(75, 192, 192, 0.2)',
          'rgba(153, 102, 255, 0.2)',
          'rgba(255, 159, 64, 0.2)',
          'rgba(255, 99, 132, 0.2)',
        ],
        borderColor: [
          'rgba(75, 192, 192, 1)',
          'rgba(153, 102, 255, 1)',
          'rgba(255, 159, 64, 1)',
          'rgba(255, 99, 132, 1)',
        ],
        borderWidth: 1,
      }
    ]
  };

  return (
    <div className="App">
      <header className="App-header">
        <h1>政党支持率</h1>
        <table className="support-table">
          <thead>
            <tr>
              <th>政党</th>
              <th>支持率 (%)</th>
              <th>投票</th>
            </tr>
          </thead>
          <tbody>
            {partySupport.map((party, index) => (
              <tr key={index}>
                <td>{party.party}</td>
                <td>{calculateSupportPercentages()[index].percentage}</td>
                <td>
                  <button 
                    className="vote-button" 
                    onClick={() => handleVote(index)}
                    disabled={voted}
                  >
                    投票
                  </button>
                  <p onClick={() => alert(party.details)} style={{ cursor: 'pointer', color: 'blue' }}>
                    詳細情報
                  </p>
                </td>
              </tr>
            ))}
          </tbody>
        </table>
        <button className="reset-button" onClick={handleReset} style={{ marginTop: '20px' }}>
          支持率をリセット
        </button>
        {voted && <p style={{ marginTop: '20px', color: 'green' }}>投票が完了しました！</p>}
        <div style={{ marginTop: '40px', width: '50%', margin: 'auto' }}>
          <Bar data={chartData} options={{ responsive: true }} />
        </div>
        <h2>全体の投票数: {totalVotes}</h2>
        <h2>フィードバック</h2>
        <textarea
          value={feedback}
          onChange={handleFeedbackChange}
          placeholder="あなたの意見をここに書いてください"
          rows="4"
          style={{ width: '80%', margin: '10px auto' }}
        />
        <button onClick={submitFeedback}>意見を送信</button>
        <div>
          <h3>送信された意見</h3>
          <ul>
            {feedbackList.map((item, index) => (
              <li key={index}>{item}</li>
            ))}
          </ul>
        </div>
      </header>
    </div>
  );
}

export default App;
