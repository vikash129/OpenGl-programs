import React, { useRef, useEffect, useState } from 'react'

export const SketchGame = () => {

    const canvasRef = useRef(null)
    const [ctx, setCtx] = useState(null)
    const [draw, setDraw] = useState(false)

    useEffect(() => {
        const canvas = canvasRef.current

        canvas.width = window.innerWidth * 2
        canvas.height = window.innerHeight * 2
        canvas.style.width = window.innerWidth + 'px'
        canvas.style.height = window.innerHeight + 'px'

        const ctx = canvas.getContext('2d')

        ctx.scale(2, 2)
        ctx.lineCap = 'round'
        ctx.strokeStyle = 'blue'
        ctx.lineWidth  = 3


        setCtx(ctx)
    }, [])

    const startDraw = ({ nativeEvent }) => {
        const { offsetX, offsetY } = nativeEvent

        ctx.beginPath()
        ctx.moveTo(offsetX, offsetY)
        setDraw(true)

    }

    const finishDraw = () => {
        ctx.closePath()
        setDraw(false)
    }

    const Draw = (event) => {

        const { offsetX, offsetY } = event.nativeEvent

        if (draw) {
            ctx.lineTo(offsetX, offsetY)
            ctx.stroke()
        }

    }


    return (
        <div>
            <h1>Draw Sketch</h1>
            <canvas
                ref={canvasRef}
                onMouseDown={startDraw}
                onMouseUp={finishDraw}
                onMouseMove={Draw}></canvas>
        </div>
    )
}
export default SketchGame