import React, {useState} from 'react';
import axios from 'axios';
import AceEditor from "react-ace";
import "ace-builds/src-noconflict/mode-javascript";
import "ace-builds/src-noconflict/theme-monokai"

function App() {
    const [output, setOutput] = useState([]);

    function runCode(code) {
        axios.post('http://localhost:8080/', {input: code})
            .then(res => setOutput(res.data))
            .catch(err => console.log(err));
    }

    return (
        <div>
            <Input codeRunner={runCode}/>
            <Output text={output}/>
        </div>
    );
}

function Input({codeRunner}) {
    let code = "";

    function runCode() {
        codeRunner(code);
    }

    function onChangeHandler(value) {
        code = value;
    }

    return (

        <div id={"background"}>
            <div id={"h3custom"}>Crappy Code Compiler Prototype</div>
            <AceEditor
                id={"editor"}
                mode={"javascript"}
                theme={"monokai"}
                focus={true}
                onChange={value => onChangeHandler(value)}
            />
            <button id={"runbutton"} className="btn margin-top-20" onClick={runCode}>Run code</button>
        </div>
    )
}

function Output({text}) {
    return (
        <div id={"output"}>
            {text.map(output => output)}
        </div>
    )
}

export default App;